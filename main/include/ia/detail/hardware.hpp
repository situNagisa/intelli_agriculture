#pragma once

#include "./defined.h"

#if defined(NGS_SYSTEM_IS_ESP)
#	include "./hardware/esp.hpp"
#elif defined(NGS_SYSTEM_IS_WINDOWS)
#	include "./hardware/windows.hpp"
#endif