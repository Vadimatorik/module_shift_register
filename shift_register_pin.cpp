#include "shift_register_pin.h"

void ShiftRegisterPin::set ( void ) {
	uint8_t buf;
	this->cfg->sr->readByte( this->cfg->byte, &buf );
	buf |= 1 << this->cfg->bit;
	this->cfg->sr->writeByte( this->cfg->byte, buf );
	this->cfg->sr->update();
}

void ShiftRegisterPin::reset ( void ) {
	uint8_t buf;
	this->cfg->sr->readByte( this->cfg->byte, &buf );
	buf &= ~( ( uint8_t )( 1 << this->cfg->bit ) );
	this->cfg->sr->writeByte( this->cfg->byte, buf );
	this->cfg->sr->update();
}

void ShiftRegisterPin::toggle ( void ) {
	this->set( !this->read );
}

void ShiftRegisterPin::set ( bool state ) {
	if ( state ) {
		this->set();
	} else {
		this->reset();
	}
}

void ShiftRegisterPin::	set ( int state ) {
	this->set( static_cast< bool >( state ) );
}

void ShiftRegisterPin::set ( uint8_t state ) {
	this->set( static_cast< bool >( state ) );
}

bool ShiftRegisterPin::read ( void ) {
	uint8_t buf;
	this->cfg->sr->readByte( this->cfg->byte, &buf );
	buf &= 1 << this->cfg->bit;

	return static_cast< bool >( buf );
}
