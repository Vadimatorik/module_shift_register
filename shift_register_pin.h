#pragma once

#include "project_config.h"

#if defined( MODULE_SHIFT_REGISTER_ENABLED ) && \
	defined( MODULE_SHIFT_REGISTER_PIN_ENABLED )

#include "mc_hardware_interfaces_pin.h"
#include "shift_register.h"

#ifdef __cplusplus

namespace ShiftRegister {

struct PinCfg {
	const uint8_t					byte;		/// Байт в сдвиговом регистре.
	const uint8_t					bit;		/// Бит в сдвиговом регистре.
	ShiftRegister::Base*			sr;			/// Сам сдвиговый регистр.
};

class Pin : public PinBase {
public:
	Pin( const PinCfg* const cfg ) :
		cfg( cfg ) {}

public:
	void	set			(	void	);
	void	reset		(	void	);
	void	toggle		(	void	);
	void	set			(	bool	state	);
	void	set			(	int		state	);
	void	set			(	uint8_t	state	);
	bool	read		(	void	);

private:
	const PinCfg* const cfg;

};

}

#endif

#endif
