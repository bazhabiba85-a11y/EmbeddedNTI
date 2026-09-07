#include "Std_types.h"
#include "Bit_Math.h"
#include "ADC.h"

void ADC_Init (void)
{
	SET_BIT(ADMUX_Reg, 6);
	CLR_BIT(ADMUX_Reg, 7);

	SET_BIT(ADCSRA_Reg, 7);

	SET_BIT(ADCSRA_Reg, 0);
	SET_BIT(ADCSRA_Reg, 1);
	SET_BIT(ADCSRA_Reg, 2);
}

u16 ADC_Read (u8 Channel)
{
	u16 Local_u16Result = 0;

	ADMUX_Reg = (ADMUX_Reg & 0xE0) | (Channel & 0x07);

	SET_BIT(ADCSRA_Reg, 6);

	while (GET_BIT(ADCSRA_Reg, 4) == 0);

	SET_BIT(ADCSRA_Reg, 4);

	Local_u16Result = ADCL_Reg;
	Local_u16Result |= ((u16)ADCH_Reg << 8);

	return Local_u16Result;
}