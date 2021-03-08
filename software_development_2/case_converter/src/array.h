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

void initialise_array(struct array *a);

void insert_element(struct array *a, int element);

void free_array(struct array *a);

#endif
