#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

struct NGS_DLL_API screen : api::hw::screen
{
protected:
	using self_type = screen;
public:

public:

	screen() = default;
	virtual ~screen() override = default;

	virtual void flush() override
	{
		NGS_LOGL(info, "flush");
	}
	virtual void show_picture(ngs::void_ptr_cst buffer) override
	{
		NGS_LOGL(info, "show picture");
	}

private:
};


IA_DETAIL_END