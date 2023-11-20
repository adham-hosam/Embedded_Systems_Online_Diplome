/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Header file for FIFO		***************/
/**************************************************************/
/**************************************************************/

#ifndef FIFO_H_
#define FIFO_H_

#include "Platform_Types.h"
#include "stdio.h"

#include "student.h"

// Select the element type
#define data_type	struct sinfo

typedef struct buf{
    data_type* base;
    data_type* head;
    data_type* tail;
    uint32 length;
    uint32 count ;

}FIFO_Buf_t;

typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null

}FIFO_Status_t;

FIFO_Status_t FIFO_Init(FIFO_Buf_t* fifo ,data_type* buf, uint32 length );

FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t* fifo ,data_type item);

FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t* fifo ,data_type* item);

FIFO_Status_t FIFO_IsFull(FIFO_Buf_t* fifo);

void FIFO_Print(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */
