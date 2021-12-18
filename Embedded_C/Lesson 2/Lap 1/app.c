#include "uart.h"
unsigned char string1[100]="Learn_in_depth_ADHAM";
unsigned const char string2[100]="Learn_in_depth_ADHAM";

void main(void){
	uart_string(string1);
}