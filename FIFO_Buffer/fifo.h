//
// Created by Adham on 4/29/2022.
//
#ifndef FIFO_BUFFER_FIFO_H
#define FIFO_BUFFER_FIFO_H
#include <stdint.h>

#define data_type uint8_t
#define width 5
data_type uart_buffer[width];
//Type definition
typedef struct{
    data_type* base;
    data_type* head;
    data_type* tail;
    uint8_t count;
    uint8_t length;
}FIFO_BUF_t;

//FIFO status
typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
}FIFO_status;

//APIS
FIFO_status FIFO_init(FIFO_BUF_t* fifo_buf, data_type *buf, uint8_t length);
FIFO_status FIFO_enqueue(FIFO_BUF_t* fifo_buf, data_type item);
FIFO_status FIFO_dequeue(FIFO_BUF_t* fifo_buf, data_type *item);
FIFO_status FIFO_is_full(FIFO_BUF_t* fifo_buf);
void FIFO_print(FIFO_BUF_t* fifo_buf);
#endif //FIFO_BUFFER_FIFO_H
