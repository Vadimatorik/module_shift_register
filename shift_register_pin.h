/*

@startuml

namespace ShiftRegister {

Pin		--o			ShiftRegister.Base
Pin		--|>		PinBase

class Pin {
	{field}-	PinBase*				const st
	{field}-	uint8_t*				dataArray
	{field}-	const uint32_t			arraySize
	{field}-	const bool				strobActive
	{field}-	SpiMaster8BitBase*		const spiObj
	{field}-	USER_OS_STATIC_MUTEX*	const mutex
	__Constructors__
	{method}+	Pin	( const PinCfg*	const cfg )
	__Public methods__
	{method}+	void	set		( void )
	{method}+	void	reset		( void )
	{method}+	void	toggle	( void )
	{method}+	void	set		( bool	state )
	{method}+	void	set		( int		state )
	{method}+	void	set		( uint8_t	state )
	{method}+	bool	read		( void	)
}

}

@enduml

*/

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

class Pin : public McHardwareInterfaces::Pin {
public:
	Pin	(	const PinCfg*		const cfg	) :
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
