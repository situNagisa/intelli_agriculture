#include "./temperature.h"

ia::hw::sensors::temperature_t temperature::get() const
{
	return T;
}