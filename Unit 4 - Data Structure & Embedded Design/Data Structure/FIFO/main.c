/*
 * main.c
 *
 *  Created on: Oct 31, 2023
 *      Author: adham
 */

#include "fifo.h"

void main(){

	data_type i , temp = 0;
	FIFO_Buf_t Uart_FIFO;
	
	uint32_t lifo_buffer = malloc(5 * sizeof(uint32_t));

	if(	FIFO_Init(&Uart_FIFO , uart_buffer /* lifo_buffer*/ , 5 ) == FIFO_no_error)
		printf("FIFO Init ====== Done\n");

	for(i = 0 ; i< 8 ; i++){
		printf("FIFO Enqueue (%x)\n",i);
		if( FIFO_Enqueue(&Uart_FIFO , i) == FIFO_no_error)
			printf("\tFIFO Enqueue ====== Done\n");
		else
			printf("\tFIFO Enqueue ====== Failed\n");
	}

	FIFO_Print(&Uart_FIFO);

	if( FIFO_Dequeue(&Uart_FIFO , &temp) == FIFO_no_error)
		printf("FIFO Dequeue (%x) ====== Done\n", temp);
	if( FIFO_Dequeue(&Uart_FIFO , &temp) == FIFO_no_error)
			printf("FIFO Dequeue gfgfgfgfgf(%x) ====== Done\n", temp);

	FIFO_Print(&Uart_FIFO);
	FIFO_Enqueue(&Uart_FIFO , 8);
	FIFO_Print(&Uart_FIFO);


}


