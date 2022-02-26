//author:Adham Hosam

#include <stdint.h>
//#define STACK_START_SP 0X20001000
extern int main(void);
void Reset_Handler(void);
void Default_Handler ()
{
	Reset_Handler();
}
void NMI_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void H_fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void MM_fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;
void Bus_fault() __attribute__ ((weak, alias ("Default_Handler")));;
void Usage_fault_Handler() __attribute__ ((weak, alias ("Default_Handler")));;

extern unsigned int _stack_top ;
uint32_t vectors[] __attribute__ ((section(".vectors"))) = {
	
(uint32_t)	&_stack_top,
(uint32_t)  &Reset_Handler,
(uint32_t)	&NMI_Handler,
(uint32_t)	&H_fault_Handler,
(uint32_t)	&MM_fault_Handler,
(uint32_t)	&Bus_fault,
(uint32_t)	&Usage_fault_Handler,
	
};

extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS ;
extern unsigned int _E_text ;


void Reset_Handler (void){
	
	unsigned int Data_size = (unsigned char*)&_E_DATA-(unsigned char*)&_S_DATA;
	unsigned char *P_src =  (unsigned char *)&_E_text;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	int i =0;
	for(i = 0 ; i < Data_size ; i++) {
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++) ;
	}
	
	unsigned int bss_size =	(unsigned char*)&_E_BSS	-	(unsigned char*)&_S_BSS ;
	P_dst = (unsigned char*)&_S_BSS ;
	for(i = 0 ; i < bss_size ; i++) {
		*((unsigned char*)P_dst++)	=	(unsigned char)0 ;
	}
	main();
}