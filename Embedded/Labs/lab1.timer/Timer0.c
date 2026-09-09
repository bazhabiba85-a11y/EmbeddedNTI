#include <avr/io.h>
#include "Std_types.h"
#include "Bit_Math.h"
#include "TIMER0.h"

void TIMER0_voidInit(void)
{
	TCCR0 = 0x00;
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
}

void TIMER0_voidSetPreload(u8 Copy_u8Value)
{
	TCNT0 = Copy_u8Value;
}

u8 TIMER0_u8GetOverflowFlag(void)
{
	return GET_BIT(TIFR, TOV0);
}

void TIMER0_voidClearOverflowFlag(void)
{
	SET_BIT(TIFR, TOV0);
}