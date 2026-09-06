#include <avr/interrupt.h>

#include "DIO.h"
#include "BIT_MATH.h"
#include "EXTI.h"

int main(void)
{
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, OUTPUT);

	initExternalInterupts();

	sei();

	while(1)
	{
	}
}

ISR(INT0_vect)
{
	TOG_BIT(PORTC, PIN0);
}

ISR(INT1_vect)
{
	TOG_BIT(PORTC, PIN1);
}