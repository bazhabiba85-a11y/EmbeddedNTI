#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO.h"
#include "SPI.h"

int main(void) {
	SPI_voidMasterInit();

	DIO_voidSetPinDirection(DIO_PORTC, PIN0, INPUT);
	DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH); // Pull-up

	while (1) {
		if (DIO_u8GetPinValue(DIO_PORTC, PIN0) == LOW) {
			SPI_u8Transceive('1'); 
			_delay_ms(250);  
		}
	}
}