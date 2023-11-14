#pragma once

#include "./defined.h"
#include "./hardward.h"

IA_API_BEGIN

creator_type<hw::sensors::temperature> factory::create_temperature = []() -> hw::sensors::temperature*
	{
		return new detail::temperature();
	};

IA_API_END