#define F_CPU 8000000UL
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "Stepper.h"

int main(void)
{
	Stepper_voidInit();

	while (1)
	{
		Stepper_voidRotate(0, 50);
		_delay_ms(1000);

		Stepper_voidRotate(1, 50);
		_delay_ms(1000);
	}

	return 0;
}