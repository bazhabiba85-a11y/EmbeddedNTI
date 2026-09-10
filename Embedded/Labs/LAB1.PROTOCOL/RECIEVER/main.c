#define F_CPU 8000000UL
#include <avr/io.h>
#include "STD_TYPES.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "UART.h"

int main(void) {
	UART_Init();

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, PIN2, OUTPUT);

	DIO_voidSetPinValue(DIO_PORTA, PIN0, LOW);
	DIO_voidSetPinValue(DIO_PORTA, PIN1, LOW);
	DIO_voidSetPinValue(DIO_PORTA, PIN2, LOW);

	u8 received_data;

	while (1) {
		received_data = UART_ReceiveChar();

		if (received_data == '1') {
			TOG_BIT(PORTA, PIN0);
		}
		else if (received_data == '2') {
			TOG_BIT(PORTA, PIN1);
		}
		else if (received_data == '3') {
			TOG_BIT(PORTA, PIN2);
		}
	}
}