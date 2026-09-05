 #ifndef F_CPU
 #define F_CPU 8000000UL
 #endif

 #include "Std_types.h"
 #include "Bit_Math.h"
 #include "DIO.h"
 #include "LCD.h"
 #include "Keypad.h"
 #include <util/delay.h>

 void LCD_PrintNum(s32 num)
 {
	 u8 str[11];
	 s8 i = 0;

	 if (num == 0)
	 {
		 LCD_sendChar('0');
		 return;
	 }
	 if (num < 0)
	 {
		 LCD_sendChar('-');
		 num = -num;
	 }
	 while (num > 0)
	 {
		 str[i++] = (num % 10) + '0';
		 num /= 10;
	 }
	 while (--i >= 0)
	 {
		 LCD_sendChar(str[i]);
	 }
 }

 int main(void)
 {
	 u8 key = KPD_NOT_PRESSED;
	 s32 num1 = 0;
	 s32 num2 = 0;
	 u8 op = 0;
	 u8 state = 0;

	 LCD_init();
	 KPD_Init();

	 while (1)
	 {
		 key = KPD_GetPressedKey();

		 if (key != KPD_NOT_PRESSED)
		 {
			 if (key == 'C')
			 {
				 LCD_SendCommand(0x01);
				 num1 = 0;
				 num2 = 0;
				 op = 0;
				 state = 0;
			 }
			 else if (key >= '0' && key <= '9')
			 {
				 LCD_sendChar(key);
				 if (state == 0)
				 {
					 num1 = (num1 * 10) + (key - '0');
				 }
				 else
				 {
					 num2 = (num2 * 10) + (key - '0');
				 }
			 }
			 else if (key == '+' || key == '-' || key == '*' || key == '/')
			 {
				 if (state == 0)
				 {
					 op = key;
					 LCD_sendChar(key);
					 state = 1;
				 }
			 }
			 else if (key == '=')
			 {
				 LCD_sendChar('=');
				 s32 res = 0;

				 if (op == '+') res = num1 + num2;
				 else if (op == '-') res = num1 - num2;
				 else if (op == '*') res = num1 * num2;
				 else if (op == '/')
				 {
					 if (num2 != 0) res = num1 / num2;
					 else
					 {
						 LCD_SendString((u8*)"Error");
						 continue;
					 }
				 }

				 LCD_PrintNum(res);
			 }
		 }
	 }
	 return 0;
 }