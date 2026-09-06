#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "exti.h"

volatile u8 animation_mode = 0;

ISR(INT0_vect)
{
	animation_mode++;
	if (animation_mode > 2)
	{
		animation_mode = 0;
	}
}

int main(void)
{
	DIO_voidSetPortDirection(DIO_PORTC, 0xFF);

	initExternalInterupts();

	sei();

	while (1)
	{
		switch (animation_mode)
		{
			case 0:
			for (u8 i = 0; i < 8; i++)
			{
				if (animation_mode != 0) break;
				DIO_voidSetPortValue(DIO_PORTC, (1 << i));
				_delay_ms(150);
			}
			break;

			case 1:
			DIO_voidSetPortValue(DIO_PORTC, 0b10000001);
			_delay_ms(200);
			if (animation_mode != 1) break;
			
			DIO_voidSetPortValue(DIO_PORTC, 0b01000010);
			_delay_ms(200);
			if (animation_mode != 1) break;
			
			DIO_voidSetPortValue(DIO_PORTC, 0b00100100);
			_delay_ms(200);
			if (animation_mode != 1) break;
			
			DIO_voidSetPortValue(DIO_PORTA, 0b00011000);
			_delay_ms(200);
			break;

			case 2:
			DIO_voidSetPortValue(DIO_PORTC, 0xFF);
			_delay_ms(200);
			if (animation_mode != 2) break;
			
			DIO_voidSetPortValue(DIO_PORTC, 0x00);
			_delay_ms(200);
			break;
		}
	}
}