#pragma once
#include"../defined.h"

IA_DETAIL_BEGIN

struct dht : api::hw::sensors::temperature
{
	dht(ngs::embedded::io::pin_t gpio_num);
	virtual ~dht() override;

	virtual api::hw::sensors::temperature_t get()  override;

public:
	void _reset();
	void _initialize();
	bool _check();
	bool _read_bit();
	ngs::byte _read_byte();
	std::pair<ngs::float32, ngs::float32> _read_data();
private:
	api::gpio _gpio{};
};

IA_DETAIL_END
