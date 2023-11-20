#pragma once

#include "./defined.h"

IA_DETAIL_BEGIN

struct dht : api::hw::sensors::temperature
{
	dht(ngs::embedded::io::pin_t gpio_num);
	virtual ~dht() override;

	virtual api::hw::sensors::temperature_t get() const override;

private:
	void _io_out();
	void _io_in();
	void _reset();
	ngs::byte _check();

	ngs::byte _initialize();

private:
	api::gpio _gpio{};
};


IA_DETAIL_END