#pragma once

#include "project_config.h"

#ifdef MODULE_SHIFT_REGISTER_ENABLED

#include "mc_hardware_interfaces_pin.h"
#include "mc_hardware_interfaces_spi.h"
#include "user_os.h"

// SPI и GPIO должен быть инициализирован заранее.
struct ShiftRegisterStaticCfg {
	PinBase*						const st;			// Вывод, подключенный к защелке.
	uint8_t*					dataArray;			// Внутренний буфер.
	const uint32_t					arraySize;			// Размер буфера.
	const bool						strobActive;		// Состояния вывода разрешающего сигнал защелки.
	SpiMaster8BitBase*				const spiObj;		// Используемый SPI.
	USER_OS_STATIC_MUTEX*			const mutex;		// Может быть не указан (nullptr).
};

struct ShiftRegisterDinamicCfg {
	PinBase*						const st;			// Вывод, подключенный к защелке.
	const uint32_t					byteCount;			// Размер буфера.
	const bool						strobActive;		// Состояния вывода разрешающего сигнал защелки.
	SpiMaster8BitBase*				const spiObj;		// Используемый SPI.
	USER_OS_STATIC_MUTEX*			const mutex;		// Может быть не указан (nullptr).
};

class ShiftRegister {
public:
	ShiftRegister ( const ShiftRegisterStaticCfg* const cfg );
	ShiftRegister ( const ShiftRegisterDinamicCfg* const cfg );

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

#endif
