/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		KeyPad.h	   ***************/
/*****************************************************/
/*****************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define COLUMNS_NUM		4
#define ROW_NUM			4

#define KPD_PORT 		PORTD
#define KPD_DATA_DIR	DDRD
#define KPD_PIN 		PIND

#define R0	PIN0
#define R1	PIN1
#define R2	PIN2
#define R3	PIN3

#define C0	PIN4
#define C1	PIN5
#define C2	PIN6
#define C3	PIN7



#define KPD_NO_PRESSED_KEY 		0xff

#define KPD_ARR_VAL				{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

void KeyPad_Init(void);
uint8 KeyPadGetPressedKey(void);

#endif /* KEYPAD_H_ */
