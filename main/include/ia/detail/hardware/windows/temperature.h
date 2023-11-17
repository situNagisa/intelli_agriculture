#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

struct NGS_DLL_API temperature : api::hw::sensors::temperature
{
	virtual ~temperature() override = default;

	constexpr virtual api::hw::sensors::temperature_t get() const override
	{
		return T;
	}

public:
	api::hw::sensors::temperature_t T = {};
};

IA_DETAIL_END