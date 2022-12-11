#include "lifo.h"
//APIS
LIFO_Status LIFO_add_item(LIFO_Buf_t* lifo_buf, data_type item)
{
    //check LIFO is valid
    if (!lifo_buf->base || !lifo_buf->head)
        return LIFO_null;

    //check LIFO fill?
    if (lifo_buf->count == lifo_buf->length)
        return LIFO_full;

    //push item
    *(lifo_buf->head) = item;
    lifo_buf->head++;
    lifo_buf->count++;
    return LIFO_no_error;
}
LIFO_Status LIFO_get_item(LIFO_Buf_t* lifo_buf, data_type *item)
{
    //check LIFO is valid
    if (!lifo_buf->base || !lifo_buf->head)
        return LIFO_null;

    //check lifo is empty?
    if (lifo_buf->count == 0)
        return LIFO_empty;

    //Pop item
    lifo_buf->head--;
    *item = *(lifo_buf->head);
    lifo_buf->count--;
    return LIFO_no_error;
}

LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, data_type* buf, data_type length)
{
    if(buf == NULL)
        return LIFO_null;

    lifo_buf->base = buf;
    lifo_buf->head = buf;
    lifo_buf->length = length;
    lifo_buf->count = 0;
    return LIFO_no_error;
}