#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

#if !defined(IA_CONFIG_LCD_SCLK)
#	define IA_CONFIG_LCD_SCLK 36
#endif

#if !defined(IA_CONFIG_LCD_SDA)
#	define IA_CONFIG_LCD_SDA 37
#endif

#if !defined(IA_CONFIG_LCD_RST)
#	define IA_CONFIG_LCD_RST 38
#endif

#if !defined(IA_CONFIG_LCD_DC)
#	define IA_CONFIG_LCD_DC 39
#endif

#if !defined(IA_CONFIG_LCD_CS)
#	define IA_CONFIG_LCD_CS 40
#endif

#if !defined(IA_CONFIG_LCD_WIDTH)
#	define IA_CONFIG_LCD_WIDTH 128
#endif

#if !defined(IA_CONFIG_LCD_HEIGHT)
#	define IA_CONFIG_LCD_HEIGHT 160
#endif

#if !defined(IA_CONFIG_KEYBOARD_UP)
#	define IA_CONFIG_KEYBOARD_UP 4
#endif

#if !defined(IA_CONFIG_KEYBOARD_DOWN)
#	define IA_CONFIG_KEYBOARD_DOWN 5
#endif

#if !defined(IA_CONFIG_KEYBOARD_SELECT)
#	define IA_CONFIG_KEYBOARD_SELECT 6
#endif

#if !defined(IA_CONFIG_KEYBOARD_BACK)
#	define IA_CONFIG_KEYBOARD_BACK 7
#endif

IA_DETAIL_END
