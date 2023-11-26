#pragma once

#include"./dht.h"

IA_DETAIL_BEGIN

using dht_clock_type = std::chrono::system_clock;

template<class _Clock = dht_clock_type>
NGS_HPP_INLINE bool _wait_for_pin_state_in_time(const api::gpio& gpio, bool state, typename _Clock::duration timeout)
{
	using namespace std::chrono_literals;
	using clock = _Clock;

	const auto start = clock::now();
	while (clock::now() - start < timeout)
	{
		if (gpio.get() == state)
			return true;
	}

	return false;
}

NGS_HPP_INLINE dht::dht(ngs::embedded::io::pin_t gpio_num)
{
	ngs::os_api::esp::io::gpio_config config{};
	config.set_io(ngs::embedded::io::gpio::modes::io::input_output);
	config.set_pull(ngs::embedded::io::gpio::modes::pull::floating);
	NGS_ASSERT(_gpio.open(gpio_num, config));

	_initialize();
}

NGS_HPP_INLINE dht::~dht()
{
	if (_gpio.is_opened())
		_gpio.close();
}

NGS_HPP_INLINE api::hw::sensors::temperature_t dht::get()
{
	auto&& [h, t] = _read_data();

	return static_cast<api::hw::sensors::temperature_t>(t);
}

NGS_HPP_INLINE void dht::_reset()
{
	using namespace std::chrono_literals;

	_gpio.low();
	std::this_thread::sleep_for(20ms);
	_gpio.high();
	std::this_thread::sleep_for(30us);

}

NGS_HPP_INLINE void dht::_initialize()
{
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(1s);

	_reset();
	NGS_EXPECT(_check());
}

NGS_HPP_INLINE bool dht::_check()
{
	using namespace std::chrono_literals;
	constexpr auto timeout = 100us;

	if (!_wait_for_pin_state_in_time(_gpio, false, timeout))
	{
		NGS_LOGL(warn, "check gpio to false fail!");
		return false;
	}
	if (!_wait_for_pin_state_in_time(_gpio, true, timeout))
	{
		NGS_LOGL(warn, "check gpio to true fail!");
		return false;
	}

	return true;
}
inline size_t success_read_count = 0;
NGS_HPP_INLINE bool dht::_read_bit()
{
	using namespace std::chrono_literals;
	constexpr auto timeout = 100us;

	if (!_wait_for_pin_state_in_time(_gpio, false, timeout))
	{
		//NGS_LOGL(warn, "check gpio to false fail!");
		return false;
	}
	if (!_wait_for_pin_state_in_time(_gpio, true, timeout))
	{
		//NGS_LOGL(warn, "check gpio to true fail!");
		return false;
	}

	std::this_thread::sleep_for(40us);
	success_read_count++;
	return _gpio.get();
}

NGS_HPP_INLINE ngs::byte dht::_read_byte()
{
	ngs::byte data{};
	for (size_t i = 0; i < ngs::bits::as_bit(sizeof(data)); i++)
	{
		data <<= 1;
		data |= _read_bit();
	}
	return data;
}

NGS_HPP_INLINE std::pair<ngs::float32, ngs::float32> dht::_read_data()
{
	_reset();
	if (!_check())
	{
		NGS_LOGL(debug, "check fail!");
		return {};
	}
	success_read_count = 0;
	ngs::byte buffer[5]{};
	for (auto&& i : buffer)
		i = _read_byte();
	NGS_LOGL(debug, success_read_count);
	if ((buffer[0] + buffer[1] + buffer[2] + buffer[3]) != buffer[4])
		return {};

	return { static_cast<ngs::float32>(buffer[2]),static_cast<ngs::float32>(buffer[0]) };
}

IA_DETAIL_END