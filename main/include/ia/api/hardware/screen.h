﻿#pragma once

#include "./defined.h"

IA_HW_BEGIN

struct NGS_DLL_API screen
{
	virtual ~screen() = default;

	virtual void flush() = 0;
	virtual void show_picture(ngs::void_ptr_cst data) = 0;
};

IA_HW_END
