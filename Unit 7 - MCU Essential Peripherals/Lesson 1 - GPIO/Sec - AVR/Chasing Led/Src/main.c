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

int main(){

	DIO_Init();

	while(1){

		for(int  Pin =0 ; Pin < 8 ; Pin++){
			LED_Status(LED_ON , &PORTA , Pin);
			_delay_ms(200);
		}
		for(int Pin = 7; Pin >=0 ; Pin--){

			LED_Status(LED_OFF , &PORTA , Pin);
			_delay_ms(200);

		}

	}
}
