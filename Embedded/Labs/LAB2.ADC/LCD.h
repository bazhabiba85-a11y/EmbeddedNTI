#include "STD_TYPES.h"

#ifndef INCFILE1_H_
#define INCFILE1_H_

//init
void LCD_init();

//char
void LCD_sendChar(u8 Data);

//send command
void LCD_SendCommand(u8 command);

//Send String
void LCD_SendString(u8 *str);

#endif /* INCFILE1_H_ */