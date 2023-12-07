#pragma once

#include "NGS/log/log.h"
#include "NGS/embedded/embedded.h"
#include "NGS/color/color.h"

#if defined(NGS_SYSTEM_IS_ESP)
#	include "NGS/osapi/esp.h"
#endif

#define IA_BEGIN namespace ia{
#define IA_END }

IA_BEGIN

using color_t = ::ngs::colors::primaries::RGBA16;
using color_constant_t = ::ngs::colors::constant<color_t>;

inline constexpr color_t color_alpha = color_constant_t::pink;

IA_END
