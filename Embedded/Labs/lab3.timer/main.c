#include "STD_TYPES.h"
#include "TIMER1.h"
#include <util/delay.h>

int main(void)
{
	TIMER1_Init();

	while (1)
	{
		TIMER1_SetAngle(0);
		_delay_ms(1000);

		TIMER1_SetAngle(90);
		_delay_ms(1000);

		TIMER1_SetAngle(180);
		_delay_ms(1000);
	}
}