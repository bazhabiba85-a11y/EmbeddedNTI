#include <avr/io.h>
#include <avr/interrupt.h>

#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO.h"
#include "ADC.h"
#include "Timer0.h"

int main(void)
{
	u16 Local_u16AdcVal = 0;
	u16 Local_u16Temp = 0;

	DIO_voidSetPinDirection(DIO_PORTB, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, PIN2, OUTPUT);

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, INPUT);

	ADC_Init();

	TCCR0 = (1 << WGM01) | (1 << CS02) | (1 << CS00);
	TIMSK |= (1 << OCIE0);
	sei();

	while (1)
	{
		Local_u16AdcVal = ADC_Read(0);
		
		Local_u16Temp = Local_u16AdcVal / 4;
		
		if (Local_u16Temp == 0)
		{
			OCR0 = 1;
		}
		else if (Local_u16Temp > 250)
		{
			OCR0 = 250;
		}
		else
		{
			OCR0 = (u8)Local_u16Temp;
		}
	}

	return 0;
}

ISR(TIMER0_COMP_vect)
{
	TOG_BIT(PORTB, PIN0);
	TOG_BIT(PORTB, PIN1);
	TOG_BIT(PORTB, PIN2);
}