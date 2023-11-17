// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once

#include "./defined.h"
#include "../../factory.h"
#include "./screen.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE screen* factory::create_screen()
{
	return new screen();
}

IA_DETAIL_END