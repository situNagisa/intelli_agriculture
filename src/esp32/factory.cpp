#include "ia/factory.h"
#include "./sensor/temperature.h"

IA_BEGIN

creator_type<hw::sensors::temperature> factory::create_temperature = []() -> hw::sensors::temperature*
	{
		return new temperature();
	};



IA_END