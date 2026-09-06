#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"

int main(void)
{
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, INPUT);
	DIO_voidSetPinValue(DIO_PORTA, PIN0, HIGH);

	u8 Local_u8SwitchState = HIGH;

	while(1)
	{
		Local_u8SwitchState = DIO_u8GetPinValue(DIO_PORTA, PIN0);

		if (Local_u8SwitchState == LOW)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);
			_delay_ms(5000);
		}
		else
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
		}
	}

	return 0;
}
