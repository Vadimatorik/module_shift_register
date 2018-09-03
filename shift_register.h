/*

@startuml

namespace ShiftRegister {

Base --o PinBase
Base --o SpiMaster8BitBase

class Base {
	{field}-	PinBase*				const st
	{field}-	uint8_t*				dataArray
	{field}-	const uint32_t			arraySize
	{field}-	const bool				strobActive
	{field}-	SpiMaster8BitBase*		const spiObj
	{field}-	USER_OS_STATIC_MUTEX*	const mutex
	__Constructors__
	{method}+	Base ( const BaseStaticCfg*	const cfg )
	{method}+	Base ( const BaseDinamicCfg*	const cfg )
	__Public methods__
	{method}+	void		init			( void )
	{method}+	int		readByte		( uint32_t	byteNumber,\n\t\t\t\t\t  uint8_t*	returnByte )
	{method}+	int		writeByte		( uint32_t	byteNumber,\n\t\t\t\t\t  uint8_t	writeData )
	{method}+	void		update		( void )
}

}

@enduml

*/

#pragma once

#include "project_config.h"

#ifdef MODULE_SHIFT_REGISTER_ENABLED

#include "mc_hardware_interfaces_pin.h"
#include "mc_hardware_interfaces_spi.h"
#include "user_os.h"

namespace ShiftRegister {

// SPI и GPIO должен быть инициализирован заранее.
struct BaseStaticCfg {
	PinBase*						const st;			// Вывод, подключенный к защелке.
	uint8_t*					dataArray;			// Внутренний буфер.
	const uint32_t					arraySize;			// Размер буфера.
	const bool						strobActive;		// Состояния вывода разрешающего сигнал защелки.
	SpiMaster8BitBase*				const spiObj;		// Используемый SPI.
	USER_OS_STATIC_MUTEX*			const mutex;		// Может быть не указан (nullptr).
};

struct BaseDinamicCfg {
	PinBase*						const st;			// Вывод, подключенный к защелке.
	const uint32_t					byteCount;			// Размер буфера.
	const bool						strobActive;		// Состояния вывода разрешающего сигнал защелки.
	SpiMaster8BitBase*				const spiObj;		// Используемый SPI.
	USER_OS_STATIC_MUTEX*			const mutex;		// Может быть не указан (nullptr).
};

class Base {
public:
	Base ( const BaseStaticCfg* const cfg );
	Base ( const BaseDinamicCfg* const cfg );

	void		init		(	void	);

	int			readByte		(	uint32_t	byteNumber,
									uint8_t*	returnByte	);

	int			writeByte		(	uint32_t	byteNumber,
									uint8_t		writeData	);

	void		update		(	void	);

private:
	PinBase*						const st;
	uint8_t*						dataArray;
	const uint32_t					arraySize;
	const bool						strobActive;
	SpiMaster8BitBase*				const spiObj;
	USER_OS_STATIC_MUTEX*			const mutex;

};

}

#endif
