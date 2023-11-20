#pragma once
#include"../defined.h"

IA_DETAIL_BEGIN

struct dht : api::hw::sensors::temperature
{
	dht(ngs::embedded::io::pin_t gpio_num);
	virtual ~dht() override;

	virtual api::hw::sensors::temperature_t get()  override;

private:
	void _gpio_out();
	void _gpio_in();
	void _gpio_reset();
	ngs::byte _check();

	ngs::byte _initialize();

	ngs::byte _check();

	ngs::byte _read_bit();

	ngs::byte _read_byte();

	std::pair<ngs::float32,ngs::float32> _read_data();
private:
	api::gpio _gpio{};
};

IA_DETAIL_END
