#include "array.h"

#include <stdlib.h>

void initialise_array(struct array *a)
{
    a->buffer = malloc(INITIAL_BUFFER_SIZE * sizeof(int));
    a->used   = 0;
    a->size   = INITIAL_BUFFER_SIZE;
}

void insert_element(struct array *a, int element)
{
    if (a->used == a->size)
    {
        a->size  *= 2;
        a->buffer = realloc(a->buffer, a->size * sizeof(int));
    }


    a->buffer[a->used++] = element;
}

void free_array(struct array *a)
{
    free(a->buffer);
    a->buffer = NULL;
    a->used = 0;
    a->size = 0;
}
