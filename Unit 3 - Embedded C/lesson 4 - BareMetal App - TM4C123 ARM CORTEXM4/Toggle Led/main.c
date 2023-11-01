/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/ 
/**************		Layer:  main				***************/
/**************************************************************/
/**************************************************************/

#include "Platform_Types.h"

#define SYSCTL				0x400FE000
#define SYSCTL_RCGC2_R 		(*( (volatile uint32*) (SYSCTL+0x108) ))

#define GPIOF				0x40025000
#define GPIO_PORTF_DIR_R 	(*( (volatile uint32*) (GPIOF+0x400) ))
#define GPIO_PORTF_DEN_R 	(*( (volatile uint32*) (GPIOF+0x51c) ))
#define GPIO_PORTF_DATA_R 	(*( (volatile uint32*) (GPIOF+0x3FC) ))


int main()
{
	volatile uint32 Local_Delay = 0;
	// Enable the GPIO port
	SYSCTL_RCGC2_R = 0x00000020;
	
	// Wait for the GPIO to enable
	for(Local_Delay = 0 ; Local_Delay < 200 ; Local_Delay++);
	
	// Set (PF3) the direction as output
	GPIO_PORTF_DIR_R |= 1<<3;
	
	// Enable the GPIO pin
	GPIO_PORTF_DEN_R |= 1<<3;
	
	while(1){
		
		for(Local_Delay = 0 ; Local_Delay < 100000 ; Local_Delay++);
		
		// Turn on the LED (Set Pin PF3)
		GPIO_PORTF_DATA_R |= 1<<3;
		for(Local_Delay = 0 ; Local_Delay < 100000 ; Local_Delay++);
		
		// Turn off the LED (Clear Pin PF3)
		GPIO_PORTF_DATA_R &= ~(1<<3);
		
	}
	
	
	return 0;
}
