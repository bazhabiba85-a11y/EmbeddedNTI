#include <avr/io.h>
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "SPI.h"

//  ÂÌ∆… «·‹ Master
void SPI_voidMasterInit(void) {
	// ÷»ÿ « Ã«Â«  —ÃÊ· «·‹ SPI ›Ì PORTB
	// MOSI (PB5) -> Output
	// SCK  (PB7) -> Output
	// SS   (PB4) -> Output
	// MISO (PB6) -> Input
	DIO_voidSetPinDirection(DIO_PORTB, PIN5, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN7, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN4, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN6, INPUT);

	//  ›⁄Ì· «·‹ SPI Ê≈⁄œ«œÂ ﬂ‹ Master Ê÷»ÿ «· —œœ F_CPU/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_voidSlaveInit(void) {
	// MOSI (PB5) -> Input
	// SCK  (PB7) -> Input
	// SS   (PB4) -> Input
	// MISO (PB6) -> Output
	DIO_voidSetPinDirection(DIO_PORTB, PIN5, INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN7, INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN4, INPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN6, OUTPUT);

	SPCR = (1 << SPE);
}

u8 SPI_u8Transceive(u8 copy_u8Data) 
{
	SPDR = copy_u8Data;
	while (!(SPSR & (1 << SPIF))); 
	return SPDR;
}