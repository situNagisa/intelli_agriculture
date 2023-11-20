#pragma once

#include "./ldr.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE ldr::ldr(ngs::embedded::io::pin_t od)
{
	ngs::os_api::esp::io::gpio_config config{};
	config.set_io(ngs::embedded::io::gpio::modes::io::input);
	config.set_pull(ngs::embedded::io::gpio::modes::pull::down);
	NGS_ASSERT(_od.open(od, config));
}

NGS_HPP_INLINE ldr::~ldr()
{
	_od.close();
}

NGS_HPP_INLINE api::hw::sensors::lumen_t ldr::get() const
{
	return _od.get();
}


IA_DETAIL_END
