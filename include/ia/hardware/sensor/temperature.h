#pragma once

#include "./defined.h"

IA_HW_SENSOR_BEGIN

using temperature_t = float;

struct NGS_DLL_API temperature
{
	virtual ~temperature() = default;

	virtual temperature_t get() const = 0;
};

IA_HW_SENSOR_END
