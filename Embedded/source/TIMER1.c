#include <avr/io.h>
#include "STD_TYPES.h"
#include "TIMER1.h"

void TIMER1_Init(void)
{
	DDRD |= (1 << PD5);

	TCCR1A = (1 << COM1A1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);

	ICR1 = 19999;
}

void TIMER1_SetAngle(u8 angle)
{
	OCR1A = 1000 + ((u16)angle * 1000 / 180);
}