#pragma once

#include "./hardware.h"

IA_DETAIL_BEGIN


struct NGS_DLL_API factory {
#if defined(NGS_SYSTEM_IS_ESP)
	static lcd* create_screen();
	static keyboard* create_keyboard();
	static ldr* create_photosensor();
	static dht* create_temperature();
	static flashlight* create_flashlight();
	static motor* create_motor();
	static temperature_controller* create_temperature_controller();
#else
	static screen* create_screen();
	static keyboard* create_keyboard();
	static void* create_photosensor();
#endif
};

IA_DETAIL_END
