#pragma once

#include "./defined.h"

IA_HW_SENSOR_BEGIN

using lumen_t = float;

struct NGS_DLL_API light
{
	virtual ~light() = default;

	virtual lumen_t get() const { return {}; }
};

IA_HW_SENSOR_END
