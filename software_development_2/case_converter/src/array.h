#ifndef _ARRAY_H
#define _ARRAY_H

#include <stddef.h>

#define INITIAL_BUFFER_SIZE 100

struct array
{
    int *buffer;

    size_t used;
    size_t size;
};

/*
 * Initialises the array to a initial buffer size
 */
void initialise_array(struct array *a);


/*
 * Adds a new element into the buffer and keeps track of the buffer size for a
 * potential need to create a bigger buffer in the even the current buffer size
 * has been reached
 */
void insert_element(struct array *a, int element);


/*
 * Used to free the allocated memory within the heap
 */
void free_array(struct array *a);


#endif
