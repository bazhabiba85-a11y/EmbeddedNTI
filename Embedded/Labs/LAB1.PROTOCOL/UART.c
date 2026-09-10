#include <avr/io.h>
#include "STD_TYPES.h"
#include "UART.h"

void UART_Init(void)
{
	UBRRH = 0;
	UBRRL = 51;
	UCSRB = (1 << RXEN) | (1 << TXEN);
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void UART_SendChar(u8 data)
{
	while (!(UCSRA & (1 << UDRE)));

	UDR = data;
}
void UART_SendByte(u8 data)
{
	UART_SendChar(data);
}

void UART_SendString(const char *str)
{
	while (*str != '\0')
	{
		UART_SendChar(*str);
		str++;
	}
}

u8 UART_ReceiveChar(void)
{
	while (!(UCSRA & (1 << RXC)));

	return UDR;
}