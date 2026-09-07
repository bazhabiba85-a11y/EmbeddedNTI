#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "ADC.h"

#define LDR_THRESHOLD   500

int main(void)
{
	u16 adc_value = 0;

	// 1. Initialize Peripherals
	ADC_Init();
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, OUTPUT); // LED Pin PC0

	while(1)
	{
		// 2. Read LDR Analog Value from Channel 0 (PA0)
		adc_value = ADC_Read(0);

		// 3. Control LED based on Light Level
		if(adc_value < LDR_THRESHOLD)
		{
			// Dark: Turn LED ON
			DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
		}
		else
		{
			// Bright: Turn LED OFF
			DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);
		}
	}
	return 0;
}