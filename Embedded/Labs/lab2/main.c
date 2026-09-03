#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"

int main(void)
{
	DIO_voidSetPortDirection(DIO_PORTA, PORT_INPUT);
	DIO_voidSetPortValue(DIO_PORTA, PORT_HIGH);

	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, OUTPUT);

	while (1)
	{
		if (DIO_u8GetPinValue(DIO_PORTA, PIN7) == 0)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
			DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
			DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
		}
		else
		{
			if (DIO_u8GetPinValue(DIO_PORTA, PIN0) == 0)
			{
				DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);
			}

			if (DIO_u8GetPinValue(DIO_PORTA, PIN1) == 0)
			{
				DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);
			}

			if (DIO_u8GetPinValue(DIO_PORTA, PIN2) == 0)
			{
				DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
			}
			else
			{
				DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);
			}
		}
	}
}