#pragma once

#include "./defined.h"
#include "./hardward.h"

IA_API_BEGIN

NGS_HPP_INLINE creator_type<hw::sensors::temperature> factory::create_temperature = []() -> hw::sensors::temperature*
	{
		return new detail::temperature();
	};

IA_API_END