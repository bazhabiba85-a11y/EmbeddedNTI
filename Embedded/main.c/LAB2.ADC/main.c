#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"

int main(void)
{
	u16 Local_u16AdcVal = 0;
	u32 Local_u32MilliVolt = 0;
	u8 Local_u8TextBuffer[10];

	ADC_Init();
	LCD_init();

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, INPUT);

	while (1)
	{
		Local_u16AdcVal = ADC_Read(0);

		Local_u32MilliVolt = ((u32)Local_u16AdcVal * 5000) / 1023;

		Local_u8TextBuffer[0] = (Local_u32MilliVolt / 1000) + '0';
		Local_u8TextBuffer[1] = ((Local_u32MilliVolt / 100) % 10) + '0';
		Local_u8TextBuffer[2] = ((Local_u32MilliVolt / 10) % 10) + '0';
		Local_u8TextBuffer[3] = (Local_u32MilliVolt % 10) + '0';
		Local_u8TextBuffer[4] = '\0';  

		LCD_SendCommand(0x01);  
		LCD_SendString((u8*)"Volt: ");
		LCD_SendString(Local_u8TextBuffer);
		LCD_SendString((u8*)" mV");

		_delay_ms(1000);
	}

	return 0;
}