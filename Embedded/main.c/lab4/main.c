#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_types.h"
#include "DIO.h"
#include "keypad.h"

u8 SevenSegment_Array[10] = {
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111
};

int main(void)
{
	u8 key = KPD_NOT_PRESSED;

	KPD_Init();
	DIO_voidSetPortDirection(DIO_PORTD, PORT_OUTPUT);

	while (1)
	{
		key = KPD_GetPressedKey();

		if (key >= '0' && key <= '9')
		{
			DIO_voidSetPortValue(DIO_PORTD, SevenSegment_Array[key - '0']);
		}
	}

	return 0;
}