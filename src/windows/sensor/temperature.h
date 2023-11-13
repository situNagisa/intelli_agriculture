#pragma once

#include "ia/hardware/sensor/temperature.h"

struct NGS_DLL_API temperature : ia::hw::sensors::temperature
{
	virtual ~temperature() override = default;

	virtual ia::hw::sensors::temperature_t get() const override;

public:
	ia::hw::sensors::temperature_t T = {};
};
