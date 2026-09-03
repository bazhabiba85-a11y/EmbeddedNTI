/*
 * GccApplication5.c
 *
 * Created: 03/09/2026 14:57:18
 * Author : future
 */ 

#include <avr/io.h>

#define GET_BIT(reg, bitNum) ((0x01) & ((reg) >> (bitNum)))

int main(void)
{
	DDRA = 0b00000010;
	PORTA=0b00000001;

	while (1)
	{
		if (GET_BIT(PINA, 0) == 0)
		{
			PORTA = 0b00000011;
		}
		else
		{
			PORTA = 0b00000001;
		}
	}
}
