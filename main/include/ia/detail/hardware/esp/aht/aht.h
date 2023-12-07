#pragma once
#include"../defined.h"

IA_DETAIL_BEGIN

struct aht
{
	aht(::ngs::embedded::io::pin_t sda, ::ngs::embedded::io::pin_t scl, ::ngs::embedded::io::i2c::modes::address_t address);
	~aht();

	auto get()
	{
		return _read_data();
	}

	void reset();
private:
	::std::pair<float, float> _read_data();

private:
	api::i2c_master _master{};
};

IA_DETAIL_END
