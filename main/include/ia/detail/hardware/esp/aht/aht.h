#pragma once
#include"../defined.h"

IA_DETAIL_BEGIN

struct aht : api::hw::sensors::temperature
{
	aht(::ngs::embedded::io::pin_t sda, ::ngs::embedded::io::pin_t scl, ::ngs::embedded::io::bus::i2c::modes::address_t address);
	~aht();

	virtual api::hw::sensors::temperature_t get()  override
	{
		auto&& [h, t] = _read_data();
		return t;
	}

	void reset();
private:
	::std::pair<float, float> _read_data();

private:
	api::i2c_master _master{};
};

IA_DETAIL_END
