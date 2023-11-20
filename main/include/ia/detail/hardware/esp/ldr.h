#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

struct ldr : api::hw::sensors::photosensor
{
	constexpr static api::hw::sensors::lumen_t threshold = 1000;

	ldr(ngs::embedded::io::pin_t od);
	virtual ~ldr() override;

	virtual api::hw::sensors::lumen_t get() const override;


private:
	api::gpio _od{};
};

IA_DETAIL_END