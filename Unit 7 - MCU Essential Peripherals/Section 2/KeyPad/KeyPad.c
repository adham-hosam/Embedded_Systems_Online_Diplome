/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		KeyPad.c	   ***************/
/*****************************************************/
/*****************************************************/

#include "Platform_Types.h"
#include "BIT_MATH.h"

#include "KeyPad.h"
#include "DIO.h"

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
	KPD_DATA_DIR &= ~ ((1 << R0) | (1 << R1) | (1 << R2) );

	// Configure the columns as output
	KPD_DATA_DIR |= ( (1<<C0) | (1<<C1) | (1<<C2) );

	// Input => pulled-up , Output=> High
	KPD_PORT = PORT_OUTPUT;

}
uint8 KeyPadGetPressedKey(void)
{
	uint32 col , row;
	for( col = 0 ; col < 4 ; col++){

		// Set all column pins as high
		KPD_PORT |= ( (1 << Key_padCol[0] ) | (1 << Key_padCol[1] ) | (1 << Key_padCol[2] ) | (1 << Key_padCol[3] ) );

		// Clear each column pin at a time to know which column had been pressed
		KPD_PORT &= ~(1 << Key_padCol[col]);

		for(row = 0 ; row < 4 ; row++){

			if(GET_BIT(KPD_PIN , Key_padRow[row]) == 0){

				// Wait until the button is released
				while(GET_BIT(KPD_PIN , Key_padRow[row]) == 0);

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
