#ifndef DIO_H_
#define DIO_H_

#define INPUT       0
#define OUTPUT      1

#define LOW         0
#define HIGH        1

#define PORT_INPUT  0b00000000
#define PORT_OUTPUT 0b11111111

#define PORT_LOW  0b00000000
#define PORT_HIGH 0b11111111

#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2
#define DIO_PORTD   3

#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7

void DIO_voidSetPinDirection(u8 PortId, u8 PinId, u8 Direction);
void DIO_voidSetPinValue(u8 PortId, u8 PinId, u8 Value);
u8   DIO_u8GetPinValue(u8 PortId, u8 PinId);

void DIO_voidSetPortDirection(u8 PortId, u8 Direction);
void DIO_voidSetPortValue(u8 PortId, u8 Value);

#endif