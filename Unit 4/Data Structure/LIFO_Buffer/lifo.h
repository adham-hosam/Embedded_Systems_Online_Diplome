//
// Created by Adham on 4/28/2022.
//
#ifndef LIFO_BUFFER_LIFO_H
#define LIFO_BUFFER_LIFO_H
#include <stdint.h>
#define data_type uint8_t
//Type definition
typedef struct {
    data_type length;
    data_type count;
    data_type *base;
    data_type * head;
}LIFO_Buf_t;

//Lifo Status
typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null
}LIFO_Status;

//APIS
LIFO_Status LIFO_add_item(LIFO_Buf_t* lifo_buf, data_type item);
LIFO_Status LIFO_get_item(LIFO_Buf_t* lifo_buf, data_type *item);
LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, data_type* buf, data_type length);

#endif //LIFO_BUFFER_LIFO_H
