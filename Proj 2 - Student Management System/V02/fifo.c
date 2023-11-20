/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Source file for FIFO		***************/
/**************************************************************/
/**************************************************************/

#include "fifo.h"

FIFO_Status_t FIFO_Init(FIFO_Buf_t* fifo ,data_type* buf, uint32 length ){

    if(buf == NULL)
        return FIFO_null;

    // Initialize the FIFO buffer.
    fifo->base = buf;
    fifo->head = buf;
    fifo->tail = buf;
    fifo->length = length;
    fifo->count = 0;

    return FIFO_no_error;	// Return FIFO_no_error to indicate successful initialization.

}

FIFO_Status_t FIFO_Enqueue(FIFO_Buf_t* fifo ,data_type item){

    // Check if FIFO exist
    if( !fifo->base || !fifo->head || !fifo-> tail )
        return FIFO_null;

    // Check if the FIFO is full.
    if ( FIFO_IsFull(fifo) == FIFO_full )
        return FIFO_full;

    // Add the item to the FIFO.
    *(fifo->head) = item;
    fifo->count++;

    //circular FIFO
    if(	fifo->head == (	fifo->base + (	fifo->length * sizeof(data_type) ) ) )
        fifo->head = fifo->base;
    else
        fifo->head++;

    return FIFO_no_error;
}

FIFO_Status_t FIFO_Dequeue(FIFO_Buf_t* fifo ,data_type* item){

    // Check if FIFO exist
    if( !fifo->base || !fifo->head || !fifo-> tail )
        return FIFO_null;

    // Check if the FIFO is empty.
    if ( fifo->count == 0 )
        return FIFO_empty;

    // Pop an item from the FIFO.
    *item = *(fifo->tail);
    fifo->count--;

    //circular FIFO
    if(	fifo->tail == (	fifo->base + (	fifo->length * sizeof(data_type) ) ) )
        fifo->tail = fifo->base;
    else
        fifo->tail++;


    return FIFO_no_error;
}

FIFO_Status_t FIFO_IsFull(FIFO_Buf_t* fifo){

    // Check if FIFO exist
    if( !fifo->base || !fifo->head || !fifo->tail )
        return FIFO_null;

    // Check if the FIFO is full.
    if(fifo->count == fifo->length)
        return FIFO_full;

    return FIFO_no_error;
}

void FIFO_Print(FIFO_Buf_t* fifo){

    data_type* temp;
    int i;

    if ( fifo->count == 0 )
    {
        printf("FIFO is Empty\n");
    }

    else{
        temp = fifo->tail;
        printf("=========== FIFO Print ===========\n ");

        for(i = 0 ; i < fifo->count; i++)
        {
            printf("\t\t%x\n",*temp);
            temp++;

        }
        printf("\t==================\n");
    }

}
