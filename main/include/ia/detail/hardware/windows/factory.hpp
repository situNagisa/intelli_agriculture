// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once

#include "./defined.h"
#include "../../factory.h"
#include "./screen.h"
#include "./keyboard.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE screen* factory::create_screen()
{
	return new screen();
}

NGS_HPP_INLINE inline keyboard* factory::create_keyboard()
{
	return new keyboard();
}


IA_DETAIL_END