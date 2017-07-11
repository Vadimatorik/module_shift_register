#include "module_shift_register.h"

void module_shift_register::init ( void ) const {
    this->mutex = USER_OS_STATIC_MUTEX_CREATE( &this->mutex_buf );
    this->cfg->st->set( !this->cfg->strob_active );              // Переводим защелку в неактивное положение.
}

// Перезаписать все на выходах.
void module_shift_register::write ( void ) const {
    USER_OS_TAKE_MUTEX( this->mutex, portMAX_DELAY );   // Ждем, пока освободится SPI.

    this->cfg->p_spi->tx( this->cfg->buffer_out, this->cfg->number_output_byte, 10 );

    // Защелкой делаем обновление.
    this->cfg->st->set( this->cfg->strob_active );
    this->cfg->st->set( !this->cfg->strob_active );

    USER_OS_GIVE_MUTEX( this->mutex );	// Разрешаем использование SPI другим потокам.
}
