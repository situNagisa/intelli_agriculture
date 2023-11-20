#pragma once

#include "./hardware.h"

IA_DETAIL_BEGIN


struct NGS_DLL_API factory {
#if defined(NGS_SYSTEM_IS_ESP)
	static lcd* create_screen();
	static keyboard* create_keyboard();
	static ldr* create_photosensor();
#else
	static screen* create_screen();
	static keyboard* create_keyboard();
	static void* create_photosensor();
#endif
};

IA_DETAIL_END
