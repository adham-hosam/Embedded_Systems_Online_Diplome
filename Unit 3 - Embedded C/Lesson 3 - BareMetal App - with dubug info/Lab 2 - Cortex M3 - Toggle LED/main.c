/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/ 
/**************		Layer:  main				***************/
/**************************************************************/
/**************************************************************/

#include "Platform_Types.h"

#define RCC              0x40021000
#define GPIO             0x40010800
#define RCC_APB2ENR      *(volatile uint32 *)(RCC+0x18)
#define GPIO_CRH         *(volatile uint32 *)(GPIO+0x04)
#define GPIO_ODR         *(volatile uint32 *)(GPIO+0x0C)
typedef volatile uint32 vuint32_t;
typedef union {
	vuint32_t all_ports;
	struct{
		vuint32_t reserved:13;
		vuint32_t pin13:1;
	}ports;
}R_ODR_t;
volatile R_ODR_t * p_ODR = (volatile R_ODR_t*)(GPIO+0x0C);

uint8 array1[] = {1 , 2 , 3 , 4}; 			//.data section
uint8 const array2[] = {1 , 2 , 3 , 4}; 	//.rodata section


int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIO_CRH &= 0xFF0FFFFF;
	GPIO_CRH |= 0x00200000;
	while (1)
	{
		uint32 i;
		p_ODR -> ports.pin13=1;
		for( i=0;i<5000;i++);
		p_ODR ->  ports.pin13=0;
		for( i=0;i<5000;i++);
	}
}
