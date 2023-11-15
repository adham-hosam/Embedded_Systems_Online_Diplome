/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Source file for LIFO		***************/
/**************************************************************/
/**************************************************************/

#include "lifo.h"


/********************************************************************************************************
 * Syntax          : LIFO_Status LIFO_add_item(LIFO_Buf_t *lifo_buf, data_type item);
 * Description     : Adds an item to a Last-In-First-Out (LIFO) buffer.
 * Parameters (in) : lifo_buf - A pointer to the LIFO buffer structure to which the item will be added.
 *                   item - The data_type item to be added to the LIFO buffer.
 * Parameters (out): None
 * Return value    : LIFO_Status - An enumeration representing the status of the LIFO item addition.
 *                   - LIFO_no_error: Item addition was successful.
 *                   - LIFO_null: The provided LIFO buffer is not properly initialized.
 *                   - LIFO_full: The LIFO buffer is full, and no more items can be added.
 * Restrictions    : None
 * Dependencies    : None
 ********************************************************************************************************/

LIFO_Status LIFO_add_item(LIFO_Buf_t* lifo_buf, data_type item)
{
    // Check LIFO is valid
    if (!lifo_buf->base || !lifo_buf->head)
        return LIFO_null;

    // Check if the LIFO buffer is full
    if (lifo_buf->count == lifo_buf->length)
        return LIFO_full;

    // Push the item onto the buffer
    *(lifo_buf->head) = item;
    lifo_buf->head++;
    lifo_buf->count++;
    return LIFO_no_error;
}

/********************************************************************************************************
 * Syntax          : LIFO_Status LIFO_get_item(LIFO_Buf_t *lifo_buf, data_type *item);
 * Description     : Retrieves an item from a Last-In-First-Out (LIFO) buffer and stores it in the provided item.
 * Parameters (in) : lifo_buf - A pointer to the LIFO buffer structure from which to retrieve an item.
 * Parameters (out): item - A pointer to a data_type variable where the retrieved item will be stored.
 * Return value    : LIFO_Status - An enumeration representing the status of the LIFO item retrieval.
 *                   - LIFO_no_error: Item retrieval was successful.
 *                   - LIFO_null: The provided LIFO buffer is not properly initialized.
 *                   - LIFO_empty: The LIFO buffer is empty, and no item can be retrieved.
 * Restrictions    : None
 * Dependencies    : None
 ********************************************************************************************************/

LIFO_Status LIFO_get_item(LIFO_Buf_t* lifo_buf, data_type *item)
{
	// Check LIFO is valid
    if (!lifo_buf->base || !lifo_buf->head)
        return LIFO_null;

    // Check if the LIFO buffer is empty
    if (lifo_buf->count == 0)
        return LIFO_empty;

    // Pop an item from the buffer
    lifo_buf->head--;
    *item = *(lifo_buf->head);
    lifo_buf->count--;
    return LIFO_no_error;
}


/********************************************************************************************************
 * Syntax          : LIFO_Status LIFO_init(LIFO_Buf_t *lifo_buf, data_type *buf, data_type length);
 * Description     : Initializes a Last-In-First-Out (LIFO) buffer structure with the provided buffer,
 *                   length, and count.
 * Parameters (in) : lifo_buf - A pointer to the LIFO buffer structure to be initialized.
 *                   buf - A pointer to the data buffer used as the LIFO buffer.
 *                   length - The length or capacity of the LIFO buffer.
 * Parameters (out): lifo_buf - The LIFO buffer structure is initialized with the provided parameters.
 * Return value    : LIFO_Status - An enumeration representing the status of the LIFO initialization.
 *                   - LIFO_no_error: Initialization was successful.
 *                   - LIFO_null: The provided buffer pointer is null.
 * Restrictions    : None
 * Dependencies    : None
 ********************************************************************************************************/

LIFO_Status LIFO_init(LIFO_Buf_t* lifo_buf, data_type* buf, data_type length)
{
    if(buf == NULL)
        return LIFO_null;

    // Initialize the LIFO buffer with the provided buffer, length, and count
    lifo_buf->base = buf;
    lifo_buf->head = buf;
    lifo_buf->length = length;
    lifo_buf->count = 0;
    return LIFO_no_error;	// Return LIFO_no_error to indicate successful initialization
}
