#pragma once

#include "mk_hardware_interfaces_pin.h"
#include "mk_hardware_interfaces_spi.h"
#include "user_os.h"

// SPI и GPIO должен быть инициализирован заранее.
struct module_shift_register_cfg_t {
    const pin_base*               const st;                   // Вывод, подключенный к защелке.
    const uint32_t                number_output_byte;         // Колличество байт для вывода. Если 0 - вывод не используется.
          uint8_t*                const buffer_out;
    const bool                    strob_active;               // Состояния вывода разрешающего сигнал защелки.
          spi_master_8bit_base*   const p_spi;
};

class module_shift_register {
public:
    constexpr module_shift_register( const module_shift_register_cfg_t* const cfg ) : cfg(cfg) {}
    void init    ( void ) const;
    void write   ( void ) const;

private:
    const module_shift_register_cfg_t* const cfg;
    mutable USER_OS_STATIC_MUTEX_BUFFER     mutex_buf = USER_OS_STATIC_MUTEX_BUFFER_INIT_VALUE;
    mutable USER_OS_STATIC_MUTEX            mutex     = nullptr;
};
