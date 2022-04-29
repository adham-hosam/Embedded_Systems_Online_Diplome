#include <stdio.h>
#include "fifo.h"

int main() {
    data_type i, temp=0;           //data_type is equivalent to uint8_t
    FIFO_BUF_t     fifo_uart;
    if( FIFO_init(&fifo_uart, uart_buffer, 5)   ==  FIFO_no_error   )
        printf("FIFO init ------ done\n");

    for ( i = 0; i <7 ; ++i)
    {
        printf("\tFIFO enqueue (%x)\n", i);
        if (FIFO_enqueue(&fifo_uart, i) == FIFO_no_error)
            printf("\tFIFO enqueue (%x) ------ done\n", i);
        else
            printf("\tFIFO enqueue (%x) ------ failed\n", i);
    }
        FIFO_print(&fifo_uart);
        if( FIFO_dequeue(&fifo_uart , &temp)   ==  FIFO_no_error   )
            printf("\nFIFO dequeue %x ------ done\n",temp);
        if( FIFO_dequeue(&fifo_uart , &temp)   ==  FIFO_no_error   )
            printf("\nFIFO dequeue %x ------ done\n",temp);
        FIFO_print(&fifo_uart);

}
