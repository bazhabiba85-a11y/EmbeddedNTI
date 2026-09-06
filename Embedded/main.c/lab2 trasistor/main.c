#define F_CPU 8000000UL
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"

int main(void)
{
	 
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT); //  Q1 (PNP)
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, OUTPUT); //  Q2 (NPN)
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, OUTPUT); //  Q3 (PNP)
	DIO_voidSetPinDirection(DIO_PORTC, PIN3, OUTPUT); //  Q4 (NPN)
	
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, INPUT);
	DIO_voidSetPinValue(DIO_PORTA, PIN0, HIGH); // Pull-up

	while (1)
	{
		if (DIO_u8GetPinValue(DIO_PORTA, PIN0) == LOW)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);  // Q1 (PNP) -> ON
			DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);  // Q2 (NPN) -> OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH); // Q3 (PNP) -> OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN3, HIGH); // Q4 (NPN) -> ON
		}
		else
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH); // Q1 (PNP) -> OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH); // Q2 (NPN) -> ON
			DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);  // Q3 (PNP) -> ON
			DIO_voidSetPinValue(DIO_PORTC, PIN3, LOW);  // Q4 (NPN) -> OFF
		}
	}
	return 0;
}