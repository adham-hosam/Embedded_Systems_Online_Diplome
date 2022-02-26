#include "uart.h"
#define UARTODR *((volatile unsigned int*)((unsigned int*)0x101f1000))
void uart_string( unsigned char *p_string){
	while(*p_string != '\0'){
		UARTODR = (unsigned int) (*p_string);
		p_string++;
	}	
}