/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/ 
/**************		Layer:  MCAL				***************/
/**************		SWC: 	UART				***************/
/* 	 HW: VersatilePB platform, that contains an ARM926EJ-S 	  */
/**************************************************************/
/**************************************************************/

#include "uart.h"

#define UART0DR *((volatile uint32*)((uint32*)0x101f1000))

void Uart_Send_String( uint8* buffer)
{
	while(*buffer != '\0') //iterate unitl the end of the string
	{
		UART0DR = (uint32) (*buffer); //add the current character in UART0DR register
		
		buffer++;	//increment to the next character
	}
}