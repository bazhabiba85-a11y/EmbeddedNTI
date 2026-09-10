#ifndef UART_H_
#define UART_H_

#include "STD_TYPES.h"

void UART_Init(void);
void UART_SendChar(u8 data);
void UART_SendByte(u8 data);
void UART_SendString(const char *str);
u8   UART_ReceiveChar(void);

#endif