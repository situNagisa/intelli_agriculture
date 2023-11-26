﻿#pragma once

#include "./defined.h"

IA_HW_BEGIN

struct fan
{
	virtual ~fan() = default;

	virtual void on() = 0;
	virtual void off() = 0;

	virtual bool is_on() const = 0;
};

IA_HW_END
