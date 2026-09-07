#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "ADC.h"

int main(void)
{
	u16 Local_u16AdcVal = 0;
	u32 Local_u32MilliVolt = 0;
	u8 Local_u8Temp = 0;

	ADC_Init();

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, INPUT);   
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT);  
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, OUTPUT);  
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, OUTPUT);  
	DIO_voidSetPinDirection(DIO_PORTC, PIN3, OUTPUT); 

	while (1)
	{
		Local_u16AdcVal = ADC_Read(0);
		Local_u32MilliVolt = ((u32)Local_u16AdcVal * 5000) / 1023;
		Local_u8Temp = Local_u32MilliVolt / 10;

		if (Local_u8Temp < 20)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH); // Green ON
			DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);  // Yellow OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);  // Red OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN3, LOW);  // Buzzer OFF
		}
		else if (Local_u8Temp >= 20 && Local_u8Temp <= 40)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);  // Green OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH); // Yellow ON
			DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);  // Red OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN3, LOW);  // Buzzer OFF
		}
		else if (Local_u8Temp > 40)
		{
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);  // Green OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN1, LOW);  // Yellow OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH); // Red ON
			DIO_voidSetPinValue(DIO_PORTC, PIN3, HIGH); // Buzzer ON
		}

		_delay_ms(250); 
	}

	return 0;
}