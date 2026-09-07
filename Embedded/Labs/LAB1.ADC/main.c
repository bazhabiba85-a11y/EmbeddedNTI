#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "ADC.h"

int main(void)
{
	u16 Local_u16AdcVal = 0;

	ADC_Init();

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, INPUT);

	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT); // Red LED
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, OUTPUT); // Yellow LED
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, OUTPUT); // Green LED

	while (1)
	{
		Local_u16AdcVal = ADC_Read(0);

		if (Local_u16AdcVal > 0 && Local_u16AdcVal < 307)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH); // Red ON
			DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);  // Yellow OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);  // Green OFF
		}
		else if (Local_u16AdcVal >= 307 && Local_u16AdcVal <= 614)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);  // Red OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH); // Yellow ON
			DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);  // Green OFF
		}
		else if (Local_u16AdcVal > 614)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);  // Red OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);  // Yellow OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH); // Green ON
		}
		else
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);
			DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);
			DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);
		}
	}

	return 0;
}