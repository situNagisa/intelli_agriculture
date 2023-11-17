#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

#if not defined(IA_CONFIG_LCD_SCLK)
#	define IA_CONFIG_LCD_SCLK 36
#endif

#if not defined(IA_CONFIG_LCD_SDA)
#	define IA_CONFIG_LCD_SDA 37
#endif

#if not defined(IA_CONFIG_LCD_RST)
#	define IA_CONFIG_LCD_RST 38
#endif

#if not defined(IA_CONFIG_LCD_DC)
#	define IA_CONFIG_LCD_DC 39
#endif

#if not defined(IA_CONFIG_LCD_CS)
#	define IA_CONFIG_LCD_CS 40
#endif

#if not defined(IA_CONFIG_LCD_WIDTH)
#	define IA_CONFIG_LCD_WIDTH 128
#endif

#if not defined(IA_CONFIG_LCD_HEIGHT)
#	define IA_CONFIG_LCD_HEIGHT 160
#endif

IA_DETAIL_END
