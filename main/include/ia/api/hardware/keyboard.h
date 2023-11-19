#pragma once

#include "./defined.h"

IA_HW_BEGIN

enum class keyboard_code
{
	up,
	down,
	select,
	back,
};

struct NGS_DLL_API keyboard
{
	virtual ~keyboard() = default;

	virtual bool is_pressed(keyboard_code code) const = 0;
};

IA_HW_END

