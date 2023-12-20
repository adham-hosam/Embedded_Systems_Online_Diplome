/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		LCD.h	  	  ***************/
/*****************************************************/
/*****************************************************/

#ifndef LCD_H_
#define LCD_H_

#include "Stm32f103x6.h"
#include "Stm32f103x6_GPIO_Driver.h"

/* LCD Connection Configuration*/
#define LCD_DATA_PORT		GPIOA

#define LCD_CTRL_PORT		GPIOA
#define LCD_E_PIN			GPIO_PIN10
#define LCD_RW_PIN			GPIO_PIN9
#define LCD_RS_PIN			GPIO_PIN8




#define LCD_FUNCTION_8BIT_2LINES   			(0x38)
#define LCD_FUNCTION_4BIT_2LINES   			(0x28)
#define LCD_MOVE_DISP_RIGHT       			(0x1C)
#define LCD_MOVE_DISP_LEFT   				(0x18)
#define LCD_MOVE_CURSOR_RIGHT   			(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  			(0x10)
#define LCD_DISP_OFF   						(0x08)
#define LCD_DISP_ON_CURSOR   				(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   			(0x0F)
#define LCD_DISP_ON_BLINK   				(0x0D)
#define LCD_DISP_ON   						(0x0C)
#define LCD_ENTRY_DEC   					(0x04)
#define LCD_ENTRY_DEC_SHIFT   				(0x05)
#define LCD_ENTRY_INC_   					(0x06)
#define LCD_ENTRY_INC_SHIFT   				(0x07)
#define LCD_BEGIN_AT_FIRST_ROW				(0x80)
#define LCD_BEGIN_AT_SECOND_ROW				(0xC0)
#define LCD_CLEAR_SCREEN					(0x01)
#define LCD_ENTRY_MODE						(0x06)



void LCD_SendCommand(uint8 Command);
void LCD_Init(void);

void LCD_ClearScreen();

void LCD_SendChar(char Character);
void LCD_SendString(char *string);

void LCD_WriteNumber(sint64 Num);
void LCD_WriteSpecialCharacter(uint8* Pattern , uint8 PatternNumber , uint8 XPos , uint8 YPos);

void LCD_GOTO_XY(unsigned char line, unsigned char position);


;

#endif /* LCD_H_ */
