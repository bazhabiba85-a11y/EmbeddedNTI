#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KPD_NOT_PRESSED  0b11111111

void KPD_Init(void);
u8   KPD_GetPressedKey(void);

#endif