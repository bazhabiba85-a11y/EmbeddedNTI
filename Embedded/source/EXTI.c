#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "EXTI.h"

void initExternalInterupts(void)
{
	/* INT0 and INT1 as input */
	DIO_voidSetPinDirection(DIO_PORTD, PIN2, INPUT);
	DIO_voidSetPinDirection(DIO_PORTD, PIN3, INPUT);
  
    DIO_voidSetPinValue(DIO_PORTD, PIN2, HIGH);
    DIO_voidSetPinValue(DIO_PORTD, PIN3, HIGH);
	
	/* INT0 -> Interrupt on Change */
	CLR_BIT(MCUCR, ISC01);
	SET_BIT(MCUCR, ISC00);

	/* INT1 -> Interrupt on Change */
	CLR_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);

	/* Enable INT0 and INT1 */
	SET_BIT(GICR, INT0);
	SET_BIT(GICR, INT1);
}