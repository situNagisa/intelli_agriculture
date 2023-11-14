#pragma once

#include "./defined.h"

#if defined(NGS_SYSTEM_IS_WINDOWS)
#	include "./hardward/windows.h"
#elif defined(NGS_SYSTEM_IS_ESP)
#	include "./hardward/esp.h"
#endif