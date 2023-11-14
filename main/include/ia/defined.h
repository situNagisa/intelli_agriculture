#pragma once

#define NGS_USE_HPP true
#define NGS_SYSTEM_IS_ESP true
#include "NGS/log/log.h"

#if defined(NGS_SYSTEM_IS_ESP)
#	include "NGS/osapi/esp.h"
#endif

#define IA_BEGIN namespace ia{
#define IA_END }