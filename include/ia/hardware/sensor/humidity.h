#pragma once

#include "./defined.h"

IA_HW_SENSOR_BEGIN

using humidity_t = float;

struct NGS_DLL_API humidity
{
	virtual ~humidity() = default;

	virtual humidity_t get() const = 0;
};

IA_HW_SENSOR_END
