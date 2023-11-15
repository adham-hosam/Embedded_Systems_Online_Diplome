/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Header file for FIFO		***************/
/**************************************************************/
/**************************************************************/

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

// Select the element type 
#define data_type	uint8_t

#define width 5
data_type uart_buffer[width];


typedef struct{
	data_type* base;
	data_type* head;
	data_type* tail;
	uint32_t length;
	uint32_t count ;

}FIFO_Buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
	
}FIFO_Status_t;

FIFO_Status_t FIFO_Init(FIFO_Buf_t* fifo ,data_type* buf, uint32_t length );

FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t* fifo ,data_type item);

FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t* fifo ,data_type* item);

FIFO_Status_t FIFO_IsFull(FIFO_Buf_t* fifo);

void FIFO_Print(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */
