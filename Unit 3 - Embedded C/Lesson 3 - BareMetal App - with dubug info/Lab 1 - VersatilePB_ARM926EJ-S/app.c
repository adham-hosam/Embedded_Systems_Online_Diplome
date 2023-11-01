
#include "uart.h"

uint8 string_buffer[100] = "Learn-in-depth: Adham Hossam";	//.data section

const uint8 var[100] = ".rodate section"; //.rodate section
uint8 var2[100];	//.bss section in RAM

void main(void){

	Uart_Send_String(string_buffer);
	
}