#pragma once

#include "./hardware.h"

IA_BEGIN

template<class _T>
using creator_type = _T * (*)();

struct NGS_DLL_API factory {
	static creator_type<hw::screen> create_screen;
	static creator_type<hw::keyboard> create_keyboard;
	static creator_type<hw::sensors::temperature> create_temperature;
	static creator_type<hw::sensors::humidity> create_humidity;
	static creator_type<hw::sensors::light> create_light;
};

IA_END
