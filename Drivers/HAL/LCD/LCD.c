/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		LCD.c	  	  ***************/
/*****************************************************/
/*****************************************************/


#include "BIT_MATH.h"


#include "LCD.h"


GPIO_PinConfig_t PinCfg;


static void busyWait(int iterations) {
	for (int i = 0; i < iterations; ++i) {
		// Perform some dummy operations to simulate busy waiting
		for (int j = 0; j < 255; ++j) {
			// Do nothing, just waste time
		}
	}
}

static void LCD_PinConfig(void){

	PinCfg.GPIO_PIN = LCD_E_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL_PORT ,&PinCfg);

	PinCfg.GPIO_PIN = LCD_RW_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL_PORT ,&PinCfg);

	PinCfg.GPIO_PIN = LCD_RS_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(LCD_CTRL_PORT ,&PinCfg);

	for(int i = GPIO_PIN0 ; i <= GPIO_PIN7 ; i++){
		PinCfg.GPIO_PIN = i;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
		MCAL_GPIO_Init(LCD_DATA_PORT ,&PinCfg);
	}
}

static void LCD_SendData(uint8 Data)
{
	// Set Data to data pins
	MCAL_GPIO_WritePort( LCD_DATA_PORT , Data);

	// Set RS pin to high for data
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RS_PIN , GPIO_PinStatus_HIGH);

	// Set RW pin to low for write
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_RW_PIN , GPIO_PinStatus_LOW);

	// Send enable pulse
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_E_PIN , GPIO_PinStatus_HIGH);
	busyWait(2);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_E_PIN , GPIO_PinStatus_LOW);
}

void LCD_SendCommand(uint8 Command)
{

	// Set RS pin to low for command
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN, GPIO_PinStatus_LOW);

	// Set RW pin to low for write
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, LCD_RW_PIN, GPIO_PinStatus_LOW);


	/*Set command to data pins*/
	MCAL_GPIO_WritePort(LCD_DATA_PORT , Command);

	// Send enable pulse
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_E_PIN , GPIO_PinStatus_HIGH);
	busyWait(2);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT , LCD_E_PIN , GPIO_PinStatus_LOW);
}




void LCD_Init(void)
{
	LCD_PinConfig();

	/*Wait for more than 30 ms*/
	busyWait(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	LCD_SendCommand(LCD_FUNCTION_8BIT_2LINES);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	LCD_SendCommand(LCD_DISP_ON);

	/*Clear display*/
	LCD_SendCommand(LCD_CLEAR_SCREEN);

	LCD_SendCommand(LCD_DISP_ON_CURSOR);
}

void LCD_ClearScreen(){
	LCD_SendCommand(LCD_CLEAR_SCREEN);
}




void LCD_SendChar(char character) {
	static int count = 0;

	LCD_SendData(character);
	count++;

	// Add a small delay to make the text writing visible
	busyWait(40); // Adjust the delay duration as needed

	if (count == 16) {
		// Move to the second line when the first line is full
		LCD_GOTO_XY(1, 0);
	} else if (count == 32) {
		// Small delay before clearing the screen
		busyWait(25);
		// Clear the screen and move back to the first line
		LCD_ClearScreen();
		LCD_GOTO_XY(0, 0);
		count = 0;
	}
}


void LCD_SendString(char *string) {
	int count = 0;

	while (*string != '\0') {
		count++;
		LCD_SendData(*string);

		// Add a small delay to make the text writing visible
		busyWait(35);

		if (count == 16) {
			// Move to the second line when the first line is full
			LCD_GOTO_XY(1, 0);
		} else if (count == 32) {
			// Small delay before clearing the screen
			busyWait(25);

			// Clear the screen and move back to the first line
			LCD_ClearScreen();
			LCD_GOTO_XY(0, 0);
			count = 0;
		} else if (count % 16 == 0) {
			// Move to the next line after every 16 characters
			LCD_GOTO_XY(count / 16, 0);
		}

		string++;
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


