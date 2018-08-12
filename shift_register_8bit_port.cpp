#include "shift_register_8bit_port.h"

void ShiftRegisterPort8bit::write ( uint8_t data ) {
	this->cfg->sr->writeByte( this->cfg->byte, data );
	this->cfg->sr->update();
}

void ShiftRegisterPort8bit::reset ( void ) {
	this->cfg->sr->writeByte( this->cfg->byte, 0 );
	this->cfg->sr->update();
}

void ShiftRegisterPort8bit::toggle ( void ) {
	uint8_t	data;
	this->cfg->sr->readByte( this->cfg->byte, &data );
	data = ~data;
	this->cfg->sr->writeByte( this->cfg->byte, data );
	this->cfg->sr->update();
}

uint8_t ShiftRegisterPort8bit::read ( void ) {
	uint8_t	data;
	this->cfg->sr->readByte( this->cfg->byte, &data );
	return data;
}
