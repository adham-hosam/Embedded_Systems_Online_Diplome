/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		 Startup.c Cortex M3		***************/
/**************************************************************/
/**************************************************************/

#include "Platform_Types.h"
//#define STACK_START_SP 0X20001000

// Function prototypes
extern int main(void);
void Reset_Handler(void);
void Default_Handler ()
{
	Reset_Handler();
}

// Weakly aliased exception handlers
void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void MM_fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_fault() __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;


// Symbols defined in the linker script
extern uint32 _stack_top ;
extern uint32 _S_DATA ;
extern uint32 _E_DATA ;
extern uint32 _S_BSS;
extern uint32 _E_BSS ;
extern uint32 _E_text ;

// Interrupt vector table
uint32 vectors[] __attribute__ ((section(".vectors"))) = {
	
(uint32)	&_stack_top,
(uint32)  	&Reset_Handler,
(uint32)	&NMI_Handler,
(uint32)	&H_fault_Handler,
(uint32)	&MM_fault_Handler,
(uint32)	&Bus_fault,
(uint32)	&Usage_fault_Handler,
	
};



// Reset Handler function
void Reset_Handler (void){
	
	/// Calculate the size of initialized data section
	uint32 Data_size = (uint8*)&_E_DATA-(uint8*)&_S_DATA;
	
	// Copy data from flash to RAM (initialized data)
	uint8 *P_src =  (uint8 *)&_E_text;
	uint8* P_dst = (uint8*)&_S_DATA;
	uint32 i =0;
	for(i = 0 ; i < Data_size ; i++) {
		*((uint8*)P_dst++) = *((uint8*)P_src++) ;
	}
	
	// Copy data from flash to RAM (initialized data)
	uint32 bss_size =	(uint8*)&_E_BSS	-	(uint8*)&_S_BSS ;
	
	// Initialize BSS section to zero
	P_dst = (uint8*)&_S_BSS ;
	for(i = 0 ; i < bss_size ; i++) {
		*((uint8*)P_dst++)	=	(uint8)0 ;
	}
	
	// Call the 'main' function to start the application
	main();
}