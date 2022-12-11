#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"
data_type buffer1[5];    //5*4 = 20Bytes        data_type is equivalent to uint8_t

int main() {
    int i, temp = 0;
    LIFO_Buf_t uart_lifo, I2c_lifo;
    //Static allocation
    LIFO_init(&uart_lifo, buffer1, 5);
    //Dynamic allocation
    data_type* buffer2 = (data_type*)malloc(5* sizeof(data_type));
    LIFO_init(&I2c_lifo, buffer2,5);

    //Adding data to the LIFO
    for ( i = 0; i <5 ; ++i) {
        if (    LIFO_add_item(&uart_lifo, i) == LIFO_no_error )
            printf("Uart_LIFO added: %d\n",i);
    }

    //Pop data from the LIFO
    for ( i = 0; i <5 ; ++i) {
        if (LIFO_get_item(&uart_lifo, (uint8_t *) &temp) == LIFO_no_error )
            printf("Uart_LIFO Pop: %d\n",temp);
    }
    return 0;
}
