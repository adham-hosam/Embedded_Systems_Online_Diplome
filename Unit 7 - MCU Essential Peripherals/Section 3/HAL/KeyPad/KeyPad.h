/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		KeyPad.h	   ***************/
/*****************************************************/
/*****************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Stm32f103x6.h"
#include "Stm32f103x6_GPIO_Driver.h"

// Define the number of rows and columns in the keypad
#define COL_NUM			4
#define ROW_NUM			4

#define KPD_PORT 	GPIOB

// Define the pins corresponding to each row
#define R0	GPIO_PIN0
#define R1	GPIO_PIN1
#define R2	GPIO_PIN3
#define R3	GPIO_PIN4

// Define the pins corresponding to each column
#define C0	GPIO_PIN5
#define C1	GPIO_PIN6
#define C2	GPIO_PIN7
#define C3	GPIO_PIN8

// Define the keypad configuration array
#define KeyPadConfig {\
						{'7', '8', '9', '/'},\
						{'4', '5', '6', '*'},\
						{'1', '2', '3', '-'},\
						{'!', '0', '=', '+'}\
}

void KeyPad_Init(void);
uint8 KeyPadGetPressedKey(void);

#endif /* KEYPAD_H_ */
