// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once

#include "./defined.h"
#include "../../factory.h"
#include "./config.h"
#include "./lcd.h"
#include "./keyboard.h"
#include "./ldr.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE lcd* factory::create_screen()
{
	return new lcd(
		IA_CONFIG_LCD_SCLK, IA_CONFIG_LCD_SDA, IA_CONFIG_LCD_CS, IA_CONFIG_LCD_DC, IA_CONFIG_LCD_RST, IA_CONFIG_LCD_WIDTH, IA_CONFIG_LCD_HEIGHT
	);
}

NGS_HPP_INLINE keyboard* factory::create_keyboard()
{
	return new keyboard(
		IA_CONFIG_KEYBOARD_UP, IA_CONFIG_KEYBOARD_DOWN, IA_CONFIG_KEYBOARD_SELECT, IA_CONFIG_KEYBOARD_BACK
	);
}

NGS_HPP_INLINE ldr* factory::create_photosensor()
{
	return new ldr(IA_CONFIG_LDR_OD);
}



IA_DETAIL_END