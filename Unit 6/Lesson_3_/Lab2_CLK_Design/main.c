/****************************************************************************************/
/****************************************************************************************/
/*******************    Author 	    : Adham Hossam    			*************************/
/*******************    Description : System Clock Initialize   *************************/
/****************************************************************************************/
/****************************************************************************************/

#include "PLATFORM_TYPES.h"

#define RCC_BASE_ADDRESS		0x40021000
#define RCC_CFGR				*((volatile u32*)( RCC_BASE_ADDRESS + 0x04) )

void RCC_voidInitSysClock(void)
{
	/*HSI is selected by default 8-MHZ*/
	RCC_CFGR |= (0b101 << 11);		/*Set APB2 Clock to 2MHZ */
	RCC_CFGR |= (0b100 << 8 );		/*Set APB2 Clock to 4MHZ */
}

void main(void)
{
	/*Initialize Clock System*/
	RCC_voidInitSysClock();
	while(1)
	{

	}
}
