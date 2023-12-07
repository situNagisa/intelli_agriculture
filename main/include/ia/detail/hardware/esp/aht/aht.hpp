#pragma once

#include "./aht.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE aht::aht(::ngs::embedded::io::pin_t sda, ::ngs::embedded::io::pin_t scl, ::ngs::embedded::io::i2c::modes::address_t address)
{
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(20ms);

	_master.open(sda, scl, address);
	_master.set_ack(::ngs::embedded::io::i2c::modes::ack::any);

	_master.write(0xA8, 0x00, 0x00);
	std::this_thread::sleep_for(300ms);
	_master.write(0xE1, 0x08, 0x00);
	std::this_thread::sleep_for(300ms);
}

NGS_HPP_INLINE aht::~aht()
{
	_master.close();
}

NGS_HPP_INLINE void aht::reset()
{

}

NGS_HPP_INLINE::std::pair<float, float> aht::_read_data()
{
	using namespace std::chrono_literals;

	_master.write(0xAC, 0x00, 0x00);
	::ngs::byte data[6]{};
	_master.set_ack(ngs::embedded::io::i2c::modes::ack::last_no_ack);
	_master.read(data);
	_master.set_ack(ngs::embedded::io::i2c::modes::ack::any);

	float humidity =
		static_cast<::ngs::float32>(static_cast<::ngs::uint32>((data[1] << 12) | (data[2] << 4) | (data[3] & 0xF0))) *
		1.0f / static_cast<::ngs::float32>(1ull << 20);
	float temperature =
		static_cast<::ngs::float32>(static_cast<::ngs::uint32>(((data[3] & 0x0F) << 16) | (data[4] << 8) | (data[5]))) *
		200.0f / static_cast<::ngs::float32>(1ull << 20) - 50.0f;

	return { humidity,temperature };
}

IA_DETAIL_END
