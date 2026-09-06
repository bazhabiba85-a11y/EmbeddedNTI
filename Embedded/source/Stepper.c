#define F_CPU 8000000UL
#include <util/delay.h>

#include "Std_types.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "Stepper.h"

static u8 Local_u8StepperPins[4] = {STEPPER_PIN0, STEPPER_PIN1, STEPPER_PIN2, STEPPER_PIN3};

void Stepper_voidInit(void)
{
	u8 Local_u8Index = 0;

	for (Local_u8Index = 0; Local_u8Index < 4; Local_u8Index++)
	{
		DIO_voidSetPinDirection(STEPPER_PORT, Local_u8StepperPins[Local_u8Index], OUTPUT);
		DIO_voidSetPinValue(STEPPER_PORT, Local_u8StepperPins[Local_u8Index], LOW);
	}
}

void Stepper_voidRotate(u8 Local_u8Direction, u16 Local_u16Steps)
{
	u16 Local_u16StepCounter = 0;
	u8 Local_u8StepIndex = 0;
	u8 Local_u8PinIndex = 0;

	u8 Local_u8StepSequence[4][4] = {
		{HIGH, LOW,  LOW,  LOW },
		{LOW,  HIGH, LOW,  LOW },
		{LOW,  LOW,  HIGH, LOW },
		{LOW,  LOW,  LOW,  HIGH}
	};

	for (Local_u16StepCounter = 0; Local_u16StepCounter < Local_u16Steps; Local_u16StepCounter++)
	{
		for (Local_u8StepIndex = 0; Local_u8StepIndex < 4; Local_u8StepIndex++)
		{
			for (Local_u8PinIndex = 0; Local_u8PinIndex < 4; Local_u8PinIndex++)
			{
				if (Local_u8Direction == 0)
				{
					DIO_voidSetPinValue(STEPPER_PORT, Local_u8StepperPins[Local_u8PinIndex], Local_u8StepSequence[Local_u8StepIndex][Local_u8PinIndex]);
				}
				else if (Local_u8Direction == 1)
				{
					DIO_voidSetPinValue(STEPPER_PORT, Local_u8StepperPins[Local_u8PinIndex], Local_u8StepSequence[3 - Local_u8StepIndex][Local_u8PinIndex]);
				}
			}
			_delay_ms(2);
		}
	}
}