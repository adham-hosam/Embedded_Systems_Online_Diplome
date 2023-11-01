/****************************************************************************************/
/****************************************************************************************/
/*******************    Author 	    : Adham Hossam    			*************************/
/*******************    Description : System Clock Initialize   *************************/
/****************************************************************************************/
/****************************************************************************************/
#include "PLATFORM_TYPES.h"

#define RCC_BASE_ADDRESS		0x40021000
#define RCC_CR					*((volatile u32*)( RCC_BASE_ADDRESS + 0x00) )
#define RCC_CFGR				*((volatile u32*)( RCC_BASE_ADDRESS + 0x04) )

void RCC_voidInitSysClock(void)
{
	/*HSI is selected by default 8-MHZ*/
	RCC_CFGR |= (0b10 << 0);		/*PLL selected as system clock*/
	RCC_CFGR |= (0b0110 << 18);		/*PLL input clock x8*/
	RCC_CFGR |= (0b100 << 8);		/*HCLK(APB1) divided by 2*/
	RCC_CFGR |= (0b101 << 11);		/*HCLK(APB2) divided by 4*/
	RCC_CR 	 |= (1 << 24);			/*Enable PLL*/
	
}

void main(void)
{	
	/*Initialize Clock System*/
	RCC_voidInitSysClock();
	while(1)
	{
		
	}
}
