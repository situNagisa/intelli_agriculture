﻿#pragma once

#include "./defined.h"

IA_HW_BEGIN

struct temperature_controller
{
	virtual ~temperature_controller() = default;

	virtual void on() = 0;
	virtual void off() = 0;

	virtual bool is_on() const = 0;
};

IA_HW_END
