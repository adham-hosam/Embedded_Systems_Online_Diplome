/*****************************************************/
/*****************************************************/
/*************** Author :  Adham Hossam **************/
/*************** 		GPIO.c		   ***************/
/*****************************************************/
/*****************************************************/

#include "GPIO.h"

void GPIO_Init(){

	// Configure A1 as input pull-up
	GPIOA_CRL &= 0xffffff0f;
	GPIOA_CRL |= 1<<7;
	GPIOA_ODR |= 1<<1;	// Input pull-up

	// Configure A13 as input pull-down
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 1<<23;
	GPIOA_ODR &= ~(1<<13);	// Input pull-down

	// B1 output push-pull
	GPIOB_CRL &= 0xffffff0f;
	GPIOB_CRL |= 0x00000020;


	// B13 output push-pull
	GPIOB_CRH &= 0xff0fffff;
	GPIOB_CRH |= 0x00200000;


	// Led initially off
	GPIOB_ODR |= 1<<1;
	GPIOB_ODR |= 1<<13;
}

uint8 GPIO_GetPinValue(uint8 port , uint8 pin){

	uint8 PinValue = 0;
	switch(port){
	case PORTA: PinValue = GET_BIT(GPIOA_IDR, pin); break;
	case PORTB: PinValue = GET_BIT(GPIOB_IDR, pin); break;
	default: break;
	}
	return PinValue;
}

void LED_Status(Led_Status led, uint8 port ,  uint8 pin){
	if( led == LED_OFF){
		switch(port){
		case PORTA: CLR_BIT(GPIOA_ODR , pin); break;
		case PORTB: CLR_BIT(GPIOB_ODR , pin); break;
		case PORTC: CLR_BIT(GPIOB_ODR , pin); break;
		default : break;
		}
	}
	else if(led == LED_ON){
		switch(port){
		case PORTA: SET_BIT(GPIOA_ODR , pin); break;
		case PORTB: SET_BIT(GPIOB_ODR , pin); break;
		case PORTC: SET_BIT(GPIOB_ODR , pin); break;
		default : break;
		}
	}
	else if(led == LED_TOGGLE){
		switch(port){
		case PORTA: TOG_BIT(GPIOA_ODR , pin); break;
		case PORTB: TOG_BIT(GPIOB_ODR , pin); break;
		case PORTC: TOG_BIT(GPIOB_ODR , pin); break;
		default : break;
		}
	}
	else{
		/* Wrong Choice*/
	}
}



