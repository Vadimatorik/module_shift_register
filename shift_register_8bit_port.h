/*

@startuml

ShiftRegister.Port8bit		..|>		Port8bitBase
ShiftRegister.Port8bit		--o		ShiftRegister.Base

namespace ShiftRegister {

class Port8bit {
	{field}-	const Port8bitCfg* 	const cfg
	__Constructor__
	{method}+	Port8bit	( const Port8bitCfg*	const cfg )
	__Public methods__
	{method}+	void		write		( uint8_t	data )
	{method}+	void		reset		( void )
	{method}+	void		toggle	( void )
	{method}+	uint8_t	read		( void )
}

}

@enduml

*/

#pragma once

#include "project_config.h"

#if defined( MODULE_SHIFT_REGISTER_ENABLED ) && 			\
	defined( MODULE_SHIFT_REGISTER_8BIT_PORT_ENABLED )

#include "mc_hardware_interfaces_port_8bit.h"
#include "shift_register.h"

#ifdef __cplusplus

namespace ShiftRegister {

struct Port8bitCfg {
	uint8_t					byte;		/// Байт в сдвиговом регистре.
	ShiftRegister::Base*	sr;			/// Сам сдвиговый регистр.
};

class Port8bit : public Port8bitBase {
public:
	Port8bit( const Port8bitCfg* const cfg ) :
		cfg( cfg ) {}

public:
	void		write			(	uint8_t		data	);
	void		reset			(	void	);
	void		toggle			(	void	);
	uint8_t		read			(	void	);

private:
	const Port8bitCfg* 	const cfg;

};

}

#endif

#endif
