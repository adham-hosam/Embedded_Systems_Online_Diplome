#include "Platform_Types.h"

#include "STM.h"


int main(void)
{
	RCC_Init();

	// Configure GPIOA -Pin 13 as output
	GPIO_Init();


	while(1){

		LED_Status(LED_ON);
		for(uint32 i = 0 ; i < 20000 ; i++);
		LED_Status(LED_OFF);
		for(uint32 i = 0 ; i < 20000 ; i++);

	}





}
