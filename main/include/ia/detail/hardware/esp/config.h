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
#	define IA_CONFIG_LCD_WIDTH 160
#endif

#if !defined(IA_CONFIG_LCD_HEIGHT)
#	define IA_CONFIG_LCD_HEIGHT 128
#endif

#if !defined(IA_CONFIG_LCD_PAGES)
#	define IA_CONFIG_LCD_PAGES 16
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

#if !defined(IA_CONFIG_LDR_OD)
#	define IA_CONFIG_LDR_OD 3
#endif

#if !defined(IA_CONFIG_AHT_SDA)
#	define IA_CONFIG_AHT_SDA 15
#endif

#if !defined(IA_CONFIG_AHT_SCL)
#	define IA_CONFIG_AHT_SCL 14
#endif

#if !defined(IA_CONFIG_FLASHLIGHT)
#	define IA_CONFIG_FLASHLIGHT 16
#endif

#if !defined(IA_CONFIG_MOTOR)
#	define IA_CONFIG_MOTOR 17
#endif

#if !defined(IA_CONFIG_TEMPERATURE_CONTROLLER)
#	define IA_CONFIG_TEMPERATURE_CONTROLLER 18
#endif

IA_DETAIL_END
