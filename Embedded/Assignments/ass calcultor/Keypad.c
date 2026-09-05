#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "Keypad.h"
#include <util/delay.h>

#define KPD_PORT DIO_PORTA

static u8 KPD_u8Buttons[4][4] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'C', '0', '=', '+'}
};

void KPD_Init(void)
{
	DIO_voidSetPinDirection(KPD_PORT, PIN0, OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, PIN1, OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, PIN2, OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, PIN3, OUTPUT);

	DIO_voidSetPinDirection(KPD_PORT, PIN4, INPUT);
	DIO_voidSetPinDirection(KPD_PORT, PIN5, INPUT);
	DIO_voidSetPinDirection(KPD_PORT, PIN6, INPUT);
	DIO_voidSetPinDirection(KPD_PORT, PIN7, INPUT);

	DIO_voidSetPortValue(KPD_PORT, PORT_HIGH);
}

u8 KPD_GetPressedKey(void)
{
	u8 Local_u8PressedKey = KPD_NOT_PRESSED;
	u8 row, col;

	for (row = 0; row < 4; row++)
	{
		DIO_voidSetPinValue(KPD_PORT, row, LOW);

		for (col = 0; col < 4; col++)
		{
			if (DIO_u8GetPinValue(KPD_PORT, col + 4) == LOW)
			{
				Local_u8PressedKey = KPD_u8Buttons[row][col];
				
				while (DIO_u8GetPinValue(KPD_PORT, col + 4) == LOW);
				_delay_ms(10);
			}
		}

		DIO_voidSetPinValue(KPD_PORT, row, HIGH);
	}

	return Local_u8PressedKey;
}