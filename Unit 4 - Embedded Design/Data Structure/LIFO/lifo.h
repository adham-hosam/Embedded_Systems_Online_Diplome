/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Header file for LIFO		***************/
/**************************************************************/
/**************************************************************/

#ifndef LIFO_BUFFER_LIFO_H
#define LIFO_BUFFER_LIFO_H

#include <stdint.h>
#include "stdio.h"


#define data_type uint8_t

// Type definition
typedef struct {				
    data_type length;  	// Capacity of the buffer
    data_type count;   	// Number of items in the buffer
    data_type *base;   	// Pointer to the base of the buffer
    data_type * head;  	// Pointer to the head of the buffer
}LIFO_Buf_t;

// LIFO Status
typedef enum {
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null
}LIFO_Status;

// Function prototypes for LIFO operations
LIFO_Status LIFO_add_item(LIFO_Buf_t* lifo_buf, data_type item);
LIFO_Status LIFO_get_item(LIFO_Buf_t* lifo_buf, data_type *item);
LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, data_type* buf, data_type length);

#endif /* LIFO_BUFFER_LIFO_H */
