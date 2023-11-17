// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once

#include "./defined.h"
#include "../../factory.h"
#include "./lcd.h"
#include "./config.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE lcd* factory::create_screen()
{
	return new lcd(
		IA_CONFIG_LCD_SCLK, IA_CONFIG_LCD_SDA, IA_CONFIG_LCD_CS, IA_CONFIG_LCD_DC, IA_CONFIG_LCD_RST, IA_CONFIG_LCD_WIDTH, IA_CONFIG_LCD_HEIGHT
	);
}


IA_DETAIL_END