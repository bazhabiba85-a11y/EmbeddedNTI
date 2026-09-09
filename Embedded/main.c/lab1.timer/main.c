#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "TIMER0.h"

int main(void)
{
	u32 Local_u32Counter = 0;

	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	
	TIMER0_voidInit();

	while (1)
	{
		if (TIMER0_u8GetOverflowFlag() != 0)
		{
			TIMER0_voidClearOverflowFlag();
			Local_u32Counter++;

			if (Local_u32Counter == 4)
			{
				u8 Local_u8PinState = DIO_u8GetPinValue(DIO_PORTA, PIN0);
				DIO_voidSetPinValue(DIO_PORTA, PIN0, !Local_u8PinState);
				Local_u32Counter = 0;
			}
		}
	}

	return 0;
}