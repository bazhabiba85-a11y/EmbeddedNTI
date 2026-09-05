#define F_CPU 8000000UL
#include <util/delay.h>
#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "keypad.h"

static u8 KPD_Keys[4][4] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'c', '0', '=', '+'}
};

void KPD_Init(void)
{
	DIO_voidSetPinDirection(DIO_PORTC, PIN0, INPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN1, INPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN2, INPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN3, INPUT);

	DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN3, HIGH);

	DIO_voidSetPinDirection(DIO_PORTC, PIN4, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN5, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN6, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC, PIN7, OUTPUT);

	DIO_voidSetPinValue(DIO_PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN5, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, HIGH);
}

u8 KPD_GetPressedKey(void)
{
	u8 pressed_key = KPD_NOT_PRESSED;
	u8 row, col;
	u8 pin_state;

	u8 cols_pins[4] = {PIN4, PIN5, PIN6, PIN7};
	u8 rows_pins[4] = {PIN0, PIN1, PIN2, PIN3};

	for (col = 0; col < 4; col++)
	{
		DIO_voidSetPinValue(DIO_PORTC, cols_pins[col], LOW);

		for (row = 0; row < 4; row++)
		{
			pin_state = DIO_u8GetPinValue(DIO_PORTC, rows_pins[row]);

			if (pin_state == LOW)
			{
				pressed_key = KPD_Keys[row][col];

				while (DIO_u8GetPinValue(DIO_PORTC, rows_pins[row]) == LOW);
				_delay_ms(10);
			}
		}

		DIO_voidSetPinValue(DIO_PORTC, cols_pins[col], HIGH);
	}

	return pressed_key;
}