#include "module_shift_register.h"

void module_shift_register::init ( void ) const {
	this->cfg->st->set( !this->cfg->strob_active );					// Переводим защелку в неактивное положение.
}

// Перезаписать все на выходах.
void module_shift_register::write ( void ) const {
	if ( this->cfg->mutex != nullptr )
        USER_OS_TAKE_MUTEX( *this->cfg->mutex, portMAX_DELAY );

	this->cfg->p_spi->tx( this->cfg->data_array, this->cfg->array_size, 10 );

    // Защелкой делаем обновление.
    this->cfg->st->set( this->cfg->strob_active );
    this->cfg->st->set( !this->cfg->strob_active );

    if ( this->cfg->mutex != nullptr)
        USER_OS_GIVE_MUTEX( *this->cfg->mutex );					// Разрешаем использование SPI другим потокам.
}
