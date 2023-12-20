/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		KeyPad.c	   ***************/
/*****************************************************/
/*****************************************************/


#include "KeyPad.h"


GPIO_PinConfig_t PinCfg;

// Private Macro
#define COL0	0
#define COL1	1
#define COL2	2
#define COL3	3

#define ROW0	0
#define ROW1	1
#define ROW2	2
#define ROW3	3

int Key_padRow[] = {R0, R1, R2, R3}; // Rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3}; // Columns of the keypad


void KeyPad_Init(void){


	// Configure the rows as input pull-up
	PinCfg.GPIO_PIN = R0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);

	PinCfg.GPIO_PIN = R1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);

	PinCfg.GPIO_PIN = R2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);

	PinCfg.GPIO_PIN = R3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PU;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);

	// Configure the columns as output
	PinCfg.GPIO_PIN = C0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);
	MCAL_GPIO_WritePin(KPD_PORT, C0, GPIO_PinStatus_HIGH);


	PinCfg.GPIO_PIN = C1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);
	MCAL_GPIO_WritePin(KPD_PORT, C1, GPIO_PinStatus_HIGH);

	PinCfg.GPIO_PIN = C2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);
	MCAL_GPIO_WritePin(KPD_PORT, C2, GPIO_PinStatus_HIGH);

	PinCfg.GPIO_PIN = C3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10MHz;
	MCAL_GPIO_Init(KPD_PORT ,&PinCfg);
	MCAL_GPIO_WritePin(KPD_PORT, C3, GPIO_PinStatus_HIGH);
}

uint8 KeyPadGetPressedKey(void) {
	uint32 col, row;

	static uint8 Local_u8KPDArr[ROW_NUM][COL_NUM] = KeyPadConfig;

	for (col = 0; col < COL_NUM; col++) {
		// Set all column pins as high
		for (uint32 i = 0; i < COL_NUM; i++) {
			MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[i], GPIO_PinStatus_HIGH);
		}

		// Clear each column pin at a time to know which column had been pressed
		MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[col], GPIO_PinStatus_LOW);

		for (row = 0; row < ROW_NUM; row++) {
			if (MCAL_GPIO_ReadPin(KPD_PORT, Key_padRow[row]) == GPIO_PinStatus_LOW) {
				// Wait until the button is released
				while (MCAL_GPIO_ReadPin(KPD_PORT, Key_padRow[row]) == GPIO_PinStatus_LOW);

				// Return the corresponding character from the configuration array
				return Local_u8KPDArr[row][col];
			}
		}
	}

	return ' '; // No key pressed
}


/*
uint8 KeyPadGetPressedKey(void)
{
	uint32 col , row;
	for( col = COL0 ; col <= COL3 ; col++){

		// Set all column pins as high
		MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[COL0], GPIO_PinStatus_HIGH);
		MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[COL1], GPIO_PinStatus_HIGH);
		MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[COL2], GPIO_PinStatus_HIGH);
		MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[COL3], GPIO_PinStatus_HIGH);

		// Clear each column pin at a time to know which column had been pressed
		MCAL_GPIO_WritePin(KPD_PORT, Key_padCol[col], GPIO_PinStatus_LOW);

		for(row = ROW0 ; row <= ROW3 ; row++){

			if(MCAL_GPIO_ReadPin(KPD_PORT, Key_padRow[row]) == GPIO_PinStatus_LOW){

				// Wait until the button is released
				while(MCAL_GPIO_ReadPin(KPD_PORT, Key_padRow[row]) == GPIO_PinStatus_LOW);

				switch(col){
				case (COL0):
					return (row == ROW0) ? '7' : (row == ROW1) ? '4' : (row == ROW2) ? '1' : '!';
				case COL1:
					return (row == ROW0) ? '8' : (row == ROW1) ? '5' : (row == ROW2) ? '2' : '0';
				case COL2:
					return (row == ROW0) ? '9' : (row == ROW1) ? '6' : (row == ROW2) ? '3' : '=';
				case COL3:
					return (row == ROW0) ? '/' : (row == ROW1) ? '*' : (row == ROW2) ? '-' : '+';
				default:
					break;
				}

			}
		}
	}
	return ' '; // No key pressed
}
 */
