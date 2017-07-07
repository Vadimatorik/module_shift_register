#include "module_shift_register.h"

int module_shift_register::init ( const spi_base* spi_obj ) const {
    this->spi = spi_obj;
    this->cfg->st->set( !this->cfg->strob_active );              // Переводим защелку в неактивное положение.
}

// Перезаписать все на выходах.
int module_shift_register::write ( void ) const {
    USER_OS_TAKE_MUTEX( this->mutex, portMAX_DELAY );   // Ждем, пока освободится SPI.

    this->spi->tx( this->cfg->buffer_out, this->cfg->number_output_byte, 10 );

    // Защелкой делаем обновление.
    this->cfg->st->set( this->cfg->strob_active );
    this->cfg->st->set( !this->cfg->strob_active );

    USER_OS_GIVE_MUTEX( this->mutex );	// Разрешаем использование SPI другим потокам.

    return 0;
}
