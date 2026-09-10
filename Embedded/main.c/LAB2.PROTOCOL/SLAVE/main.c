#define F_CPU 8000000UL
#include <avr/io.h> 
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "SPI.h"

int main(void) {
	SPI_voidSlaveInit();

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	DIO_voidSetPinValue(DIO_PORTA, PIN0, LOW);

	u8 received_data;

	while (1) {
		received_data = SPI_u8Transceive(0xFF);
		
		if (received_data == '1') {
			TOG_BIT(PORTA, PIN0);   
		}
	}
}