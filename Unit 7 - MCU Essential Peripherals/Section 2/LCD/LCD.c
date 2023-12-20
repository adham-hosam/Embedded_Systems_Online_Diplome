/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		LCD.c	  	  ***************/
/*****************************************************/
/*****************************************************/


#include <util/delay.h>
#include "BIT_MATH.h"

#include "DIO.h"
#include "LCD.h"


void LCD_SendCommand(uint8 Command)
{
	/*Set RS pin to low for command*/
	CLR_BIT(LCD_CTRL_PORT,LCD_RS_PIN);

	/*Set RW pin to low for write*/
	CLR_BIT(LCD_CTRL_PORT,LCD_RW_PIN);

	/*Set command to data pins*/
	LCD_DATA_PORT = Command;

	/*Send enable pulse*/
	SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	_delay_ms(2);
	CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
}

void LCD_ClearScreen(){
	LCD_SendCommand(LCD_CLEAR_SCREEN);
}



void LCD_SendData(uint8 Data)
{

	// Set RS pin to high for data
	SET_BIT(LCD_CTRL_PORT,LCD_RS_PIN);

	// Set RW pin to low for write
	CLR_BIT(LCD_CTRL_PORT,LCD_RW_PIN);

	// Set Data to data pins
	LCD_DATA_PORT = Data;

	// Send enable pulse
	SET_BIT(LCD_CTRL_PORT,LCD_E_PIN);
	_delay_ms(2);
	CLR_BIT(LCD_CTRL_PORT,LCD_E_PIN);
}

void LCD_SendChar(char Character)
{
	static uint8 currentLine = 0;
	static uint8 currentPosition = 0;

	if (currentPosition == 16)
	{
		// Switch to the next line when reaching the maximum position
		currentLine = (currentLine == 0) ? 1 : 0;
		LCD_GOTO_XY(currentLine, 0);
		currentPosition = 0;
	}

	LCD_SendData(Character);
	currentPosition++;
}

void LCD_Init(void)
{

	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	LCD_SendCommand(LCD_FUNCTION_8BIT_2LINES);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	LCD_SendCommand(LCD_DISP_ON);

	/*Clear display*/
	LCD_SendCommand(LCD_CLEAR_SCREEN);

	LCD_SendCommand(LCD_DISP_ON_CURSOR);
}

void LCD_SendString(const char* String)
{
	uint8 currentLine = 0;
	uint8 currentPosition = 0;

	for (uint32 i = 0; String[i] != '\0'; ++i)
	{
		if (currentPosition == 16)
		{
			// Switch to the next line when reaching the maximum position
			currentLine = (currentLine == 0) ? 1 : 0;
			LCD_GOTO_XY(currentLine, 0);
			currentPosition = 0;
		}

		LCD_SendData(String[i]);
		currentPosition++;
		_delay_ms(120);  // Adjust delay as needed
	}
}


void LCD_WriteNumber(sint64 Num)
{
	static uint8 Reminder = 0, int8Digits = 0;
	static sint64 ReverseNum = 0;

	/*Handling negative numbers*/
	if (Num < 0)
	{
		LCD_SendData('-');
		Num *= -1;
	}
	while (Num)
	{
		Reminder = Num % 10;
		ReverseNum = ReverseNum * 10 + Reminder;
		Num /= 10;
		int8Digits++;
	}
	while (int8Digits)
	{
		Reminder = ReverseNum % 10;
		LCD_SendData(Reminder + 48);
		ReverseNum /= 10;
		int8Digits--;
	}
}


void LCD_WriteSpecialCharacter(uint8* Pattern , uint8 PatternNumber , uint8 XPos , uint8 YPos)
{
	uint8 CGRAM8Address = 0 , Iterator;

	/* calculate CGRAM address whose each block is 8-bytes*/
	CGRAM8Address = PatternNumber * 8;

	/* send CGRAM address to LCD, with setting bit 6 */
	LCD_SendCommand(CGRAM8Address + 64);	//CGRAM8Address + 0100 0000 (64)

	/* write the pattern into the CGRAM*/
	for(Iterator = 0 ; Iterator <8 ; Iterator++)
	{
		LCD_SendData(Pattern[Iterator]);
	}

	/* go back to CGRAM tp display the pattern */
	LCD_GOTO_XY(XPos ,  YPos);

	/* display the pattern written in the CGRAM */
	LCD_SendData(PatternNumber);

}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 0)
	{
		if (position < 16 && position >= 0)
		{
			LCD_SendCommand(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_SendCommand(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}


