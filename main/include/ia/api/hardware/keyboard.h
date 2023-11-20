#pragma once

#include "./defined.h"

IA_HW_BEGIN

enum class keyboard_code
{
	up,
	down,
	select,
	back,
	max,
};

struct NGS_DLL_API keyboard
{
	virtual ~keyboard() = default;
	constexpr static size_t threshold = 10;

	virtual void update()
	{
		for (size_t i = 0; i < static_cast<size_t>(keyboard_code::max); i++)
		{
			auto&& state = _state[i];
			if (is_pressed(static_cast<keyboard_code>(i)))
			{
				if (state < threshold)
					state++;
				continue;
			}
			if (state > 0)
				state--;
		}
	}
	virtual bool is_pressed(keyboard_code code) const = 0;

	bool is_raised(keyboard_code code) const
	{
		return _state[static_cast<size_t>(code)] == (threshold - 1) && is_pressed(code);
	}
	bool is_falling(keyboard_code code) const
	{
		return _state[static_cast<size_t>(code)] == 1 && !is_pressed(code);
	}
public:
	std::array<ngs::byte, static_cast<size_t>(keyboard_code::max)> _state{};
};

IA_HW_END

