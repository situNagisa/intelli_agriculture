#pragma once

#include"./dht.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE dht::dht(ngs::embedded::io::pin_t gpio_num)
{
	ngs::os_api::esp::io::gpio_config config{};
	config.set_io(ngs::embedded::io::gpio::modes::io::input_output);
	config.set_pull(ngs::embedded::io::gpio::modes::pull::floating);
	NGS_ASSERT(_gpio.open(gpio_num, config));
}

NGS_HPP_INLINE dht::~dht()
{
		if (_gpio.is_opened())
			_gpio.close();
}

NGS_HPP_INLINE void dht::_gpio_reset()
{
	using namespace std::chrono_literals;

	_gpio_out();
	_gpio.low();
	std::this_thread::sleep_for(20ms);
	_gpio.high();
	std::this_thread::sleep_for(30us);

}

NGS_HPP_INLINE ngs::byte dht::_initialize()
{
	//
	_gpio_reset();
	return _check();
}

NGS_HPP_INLINE ngs::byte dht::_check()
{
	using namespace std::chrono_literals;

	ngs::byte retry = 0;
	_gpio_in();
	while (_gpio.get() && retry < 100)
	{
		retry++;
		std::this_thread::sleep_for(1us);
		if (retry >= 100)return 1;
		return 0;
	}
}

NGS_HPP_INLINE ngs::byte dht::_read_bit()
{
	using namespace std::chrono_literals;

	ngs::byte retry = 0;
	_gpio_in();
	while (_gpio.get() && retry < 100)
	{
		retry++;
		std::this_thread::sleep_for(1us);
	}
	ngs::byte retry = 0;
	while (!_gpio.get() && retry < 100)
	{
		retry++;
		std::this_thread::sleep_for(1us);
	}
	std::this_thread::sleep_for(40us);
	if (_gpio.get())
		return 1;
	else
		return 0;
}

NGS_HPP_INLINE ngs::byte dht::_read_byte()
{
	using namespace std::chrono_literals;
	ngs::byte i, dat;
	dat = 0;
	for (i = 0; i < 8; i++)
	{
		dat <<= 1;
		dat |= _read_bit();
	}
	return dat;
}

NGS_HPP_INLINE std::pair<ngs::float32,ngs::float32> dht::_read_data()
{
	ngs::byte buf[5];
	ngs::byte i;
	dht::_gpio_reset();
	if (dht::_check() == 0)
	{
		for (i = 0; i < 5; i++)
		{
			buf[i] = dht::_read_byte();
		}
		if ((buf[0] + buf[1] + buf[2] + buf[3]) == buf[4])
		{
			return { static_cast<ngs::float32>(buf[2]),static_cast<ngs::float32>(buf[0]) };
		}
		return { static_cast<ngs::float32>(0),static_cast<ngs::float32>(0) };
	}
	return { static_cast<ngs::float32>(0),static_cast<ngs::float32>(0) };
}

IA_DETAIL_END