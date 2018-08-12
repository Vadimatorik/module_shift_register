#pragma once

#include "project_config.h"

#if defined( MODULE_SHIFT_REGISTER_ENABLED ) && 			\
	defined( MODULE_SHIFT_REGISTER_8BIT_PORT_ENABLED )

#include "mc_hardware_interfaces_port_8bit.h"
#include "shift_register.h"

#ifdef __cplusplus

struct ShiftRegisterPort8bitCfg {
	uint8_t			byte;		/// Байт в сдвиговом регистре.
	ShiftRegister*	sr;			/// Сам сдвиговый регистр.
};

class ShiftRegisterPort8bit : public Port8bitBase {
public:
	ShiftRegisterPort8bit( const ShiftRegisterPort8bitCfg* const cfg ) :
		cfg( cfg ) {}

public:
	void		write			(	uint8_t		data	);
	void		reset			(	void	);
	void		toggle			(	void	);
	uint8_t		read			(	void	);

private:
	const ShiftRegisterPort8bitCfg* 	const cfg;

};

#endif

#endif
