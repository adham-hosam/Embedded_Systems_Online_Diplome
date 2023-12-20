/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		main.c		   ***************/
/*****************************************************/
/*****************************************************/
#include "Platform_Types.h"
#include "util/delay.h"




#include "DIO.h"

#include "Led.h"
#include "LCD.h"
#include "KeyPad.h"



uint8 customChar[] = {
		0b00000,
		0b01010,
		0b11111,
		0b11111,
		0b01110,
		0b00100,
		0b00000,
		0b00000
};


int main(){

	DIO_Init();
	LCD_Init();
	KeyPad_Init();
	/*
	const char* myString = "This is a long string that spans multiple lines. "
			"It will automatically switch to the second line when needed.";

	LCD_SendString(myString);
	*/
	uint8 x;

	while(1){

		x= KeyPadGetPressedKey();
		switch(x){
		case ' ':
			break;
		case'!':
			LCD_ClearScreen();
			break;
		default:
			LCD_SendChar(x);
			break;
		}

	}
}



