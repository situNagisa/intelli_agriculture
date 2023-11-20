#pragma once

#include "./dht.h"

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

NGS_HPP_INLINE void dht::_reset()
{
	using namespace std::chrono_literals;
	_io_out();
	_gpio.low();
	std::this_thread::sleep_for(20ms);
	_gpio.high();
	std::this_thread::sleep_for(30ms);
}

NGS_HPP_INLINE ngs::byte dht::_initialize()
{
	//
	_reset();
	return _check();
}

IA_DETAIL_END
