#pragma once

#include "mc_hardware_interfaces_pin.h"
#include "mc_hardware_interfaces_spi.h"
#include "user_os.h"

// SPI и GPIO должен быть инициализирован заранее.
struct module_shift_register_cfg_t {
	const pin_base*					const st;			// Вывод, подключенный к защелке.
	const uint8_t*					data_array;			// Внутренний буфер.
	const uint32_t					array_size;			// Размер буфера.
	const bool						strob_active;		// Состояния вывода разрешающего сигнал защелки.
	const spi_master_8bit_base*		const p_spi;		// Используемый SPI.
	const USER_OS_STATIC_MUTEX*		const mutex;		// Может быть не указан (nullptr).
};

class module_shift_register {
public:
	constexpr module_shift_register ( const module_shift_register_cfg_t* const cfg ) : cfg( cfg ) {}
	void init	( void ) const;
	void write	( void ) const;

private:
	const module_shift_register_cfg_t*		const cfg;
};
