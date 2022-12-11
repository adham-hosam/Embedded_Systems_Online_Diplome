//
// Created by Adham on 4/29/2022.
//
#include <stdio.h>
#include "fifo.h"

FIFO_status FIFO_init(FIFO_BUF_t* fifo_buf, data_type *buf, uint8_t length)
{
    //check if FIFO isn't exist
    if (fifo_buf == NULL)
        return FIFO_null;
    fifo_buf->base = buf;
    fifo_buf->head = buf;
    fifo_buf->tail = buf;
    fifo_buf->count = 0;
    fifo_buf->length = length;
    return FIFO_no_error;
}
FIFO_status FIFO_enqueue(FIFO_BUF_t* fifo_buf, data_type item)
{
    //check if FIFO isn't exist
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_null;
    //check if FIFO is full
    if (    FIFO_is_full(fifo_buf)  == FIFO_full)
        return FIFO_full;

    //Enqueuing data
    *(fifo_buf->head) = item;
    fifo_buf->count++;

    //Circular code
    if (    fifo_buf->head  == (fifo_buf->base)+(fifo_buf->length)* sizeof(data_type))
        fifo_buf->head = fifo_buf->base;
    else
        fifo_buf->head++;
    return FIFO_no_error;
}
FIFO_status FIFO_dequeue(FIFO_BUF_t* fifo_buf, data_type *item)
{
    //check if FIFO isn't exist
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_null;

    //check if the FIFO is empty
    if (  fifo_buf->count ==0 )
        return FIFO_empty;

    //De-queuing data
    *item = *(fifo_buf->tail);
    fifo_buf->count--;

    //Circular code
    if (    fifo_buf->tail  == (fifo_buf->base)+(fifo_buf->length)* sizeof(data_type))
        fifo_buf->tail = fifo_buf->base;
    else
        fifo_buf->tail++;
    return FIFO_no_error;

}
FIFO_status FIFO_is_full(FIFO_BUF_t* fifo_buf)
{
    //check if FIFO isn't exist
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_null;
    //check if FIFO is full
    if (fifo_buf->count == fifo_buf->length)
        return FIFO_full;
    return FIFO_no_error;

}
void FIFO_print(FIFO_BUF_t* fifo_buf)
{
    data_type* temp;
    int i;
    if (fifo_buf->count == 0)
        printf("\n====== FIFO is empty ======\n");
    else
    {
        temp = fifo_buf->tail;
        printf("\n------ FIFO print ------ \n");
        for ( i = 0; i <fifo_buf->count ; ++i) {
            printf("\t %x \n",*temp);
            temp++;
        }
        printf("========================\n");
    }
}

