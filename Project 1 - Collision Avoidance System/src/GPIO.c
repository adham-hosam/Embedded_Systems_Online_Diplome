/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/*************	  	SWC  :	GIO.c 				***************/
/**************************************************************/
/**************************************************************/


#include "GPIO.h"


/**************************************************************************
 * Function         : void void GPIO_Init()
 * Description      : Initializes GPIO settings for pins in GPIOA.
 * Parameters (in)  : None
 * Parameters (out) : None
 * Return value     : None
 **************************************************************************/
void GPIO_Init()
{
	// Enable Clock for GPIOA
	RCC_APB2ENR |= (1<<2);

	// Configure low bits (0-7) as input mode
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;

	// Configure pin A13 as general purpose output push-pull of speed 2 MHz.
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
}



