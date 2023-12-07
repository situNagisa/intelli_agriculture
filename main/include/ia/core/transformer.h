#pragma once

#include "./defined.h"

IA_CORE_BEGIN

struct transformer
{
	struct
	{
		size_t x{};
		size_t y{};
	}position{};
	struct
	{
		float x = 1.0f;
		float y = 1.0f;
	}size{};
	struct
	{
		float x = 1.0f;
		float y = 1.0f;
	}scale{};


};

IA_CORE_END