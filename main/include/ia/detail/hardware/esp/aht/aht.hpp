#pragma once

#include "./aht.h"

IA_DETAIL_BEGIN

NGS_HPP_INLINE aht::aht(::ngs::embedded::io::pin_t sda, ::ngs::embedded::io::pin_t scl, ::ngs::embedded::io::bus::i2c::modes::address_t address)
{
	using namespace std::chrono_literals;

	_master.open(sda, scl, address);
	_master.set_ack(::ngs::embedded::io::bus::i2c::modes::ack::any);

	::ngs::byte init_data[] = {
		0x70,
		0xE1,
		0x08,
		0x00
	};
	_master.write(init_data, ::std::extent_v<decltype(init_data)>);

	std::this_thread::sleep_for(40ms);
}

NGS_HPP_INLINE aht::~aht()
{
	_master.close();
}

NGS_HPP_INLINE void aht::reset()
{
	using namespace std::chrono_literals;

	::ngs::byte data[] = {
		0x70,
		0xE1,
		0x08,
		0x00
	};
	_master.write(data, ::std::extent_v<decltype(data)>);

	std::this_thread::sleep_for(20ms);
}

NGS_HPP_INLINE::std::pair<float, float> aht::_read_data()
{
	using namespace std::chrono_literals;

	{
		::ngs::byte data[] = {
			0x70,
			0xAC,
			0x33,
			0x00,
		};
		_master.write(data, ::std::extent_v<decltype(data)>);
	}
	::ngs::byte data[5]{};
	{
		::ngs::byte start[] = {
					0x71,
		};
		_master.write(start, ::std::extent_v<decltype(start)>);
		_master.set_ack(ngs::embedded::io::bus::i2c::modes::ack::last_no_ack);
		_master.read(data, ::std::extent_v<decltype(data)>);
		_master.set_ack(ngs::embedded::io::bus::i2c::modes::ack::any);
	}

	float humidity =
		static_cast<::ngs::float32>(static_cast<::ngs::uint32>((data[0] << 12) | (data[1] << 4) | (data[2] >> 4))) *
		100.0f / (1024 * 1024) + 0.5f;
	float temperature =
		static_cast<::ngs::float32>(static_cast<::ngs::uint32>(((data[2] & 0x0F) << 16) | (data[3] << 8) | (data[4]))) *
		2000.0f / (1024 * 1024) - 50.0f;
	temperature /= 10.0f;
	temperature -= 50;

	return { humidity,temperature };
}

IA_DETAIL_END
