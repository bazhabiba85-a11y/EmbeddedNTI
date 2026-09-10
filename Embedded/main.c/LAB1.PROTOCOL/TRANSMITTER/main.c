#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "UART.h"

int main(void) {
	UART_Init();
	
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, INPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, INPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, INPUT);
	
	DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);

	while (1) {
		if (DIO_u8GetPinValue(DIO_PORTC, PIN0) == LOW) {
			UART_SendChar('1');
			_delay_ms(250); 
		}
		else if (DIO_u8GetPinValue(DIO_PORTC, PIN1) == LOW) {
			UART_SendChar('2');
			_delay_ms(250); 
		}
		else if (DIO_u8GetPinValue(DIO_PORTC, PIN2) == LOW) {
			UART_SendChar('3');
			_delay_ms(250); 
		}
	}
}