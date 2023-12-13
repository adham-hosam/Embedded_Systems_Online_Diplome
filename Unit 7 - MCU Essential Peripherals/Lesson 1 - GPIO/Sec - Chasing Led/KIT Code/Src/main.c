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

	int Pin = PIN5;

	while(1){

		// Buzzer
		if(GET_BIT(PIND , PIN0) == HIGH){
			Buzzer(LED_ON , &PORTD , PIN4);
		}
		else{
			Buzzer(LED_OFF , &PORTD , PIN4);
		}

		// LEDs
		if(Pin <= PIN7){

			if(GET_BIT( PIND , PIN1) == HIGH)
			{
				LED_Status(LED_ON , &PORTD , Pin);
				while(GET_BIT( PIND , PIN1) == HIGH);
				Pin++;
			}
		}
		if( Pin > PIN7){
			while(Pin >PIN5){
				if(GET_BIT( PIND , PIN1) == HIGH)
				{
					LED_Status(LED_OFF , &PORTD , --Pin);
					while(GET_BIT( PIND , PIN1) == HIGH);
				}
			}

		}

	}
}



