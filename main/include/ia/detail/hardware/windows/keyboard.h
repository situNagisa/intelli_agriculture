#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

struct NGS_DLL_API keyboard : api::hw::keyboard
{
protected:
	using self_type = keyboard;
public:

public:

	keyboard() = default;
	virtual ~keyboard() override = default;

	virtual bool is_pressed(api::hw::keyboard_code code) const override
	{
		return false;
	}

private:
};


IA_DETAIL_END