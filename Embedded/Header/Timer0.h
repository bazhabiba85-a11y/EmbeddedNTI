#ifndef TIMER0_H_
#define TIMER0_H_

#include "Std_types.h"

void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(u8 Copy_u8Value);
void TIMER0_voidClearOverflowFlag(void);
u8   TIMER0_u8GetOverflowFlag(void);

#endif