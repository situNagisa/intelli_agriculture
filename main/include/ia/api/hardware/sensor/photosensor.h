#pragma once

#include "./defined.h"

IA_HW_SENSOR_BEGIN

using lumen_t = float;

struct NGS_DLL_API photosensor
{
	virtual ~photosensor() = default;

	virtual lumen_t get() const { return {}; }
};

IA_HW_SENSOR_END
