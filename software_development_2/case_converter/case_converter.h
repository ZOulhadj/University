#ifndef _CASE_CONVERTER_H
#define _CASE_CONVERTER_H


#include <stdbool.h>
#include <stddef.h>

#define MAX_BUFFER_SIZE 500

enum cases
{
    UPPER_CASE,
    LOWER_CASE
};


enum input
{
    FILE_INPUT,
    USER_INPUT
};


enum output
{
    FILE_OUTPUT,
    USER_OUTPUT
};


struct arguments
{

    enum cases case_conversion;

    bool count;
    size_t word_count;

    int buffer[MAX_BUFFER_SIZE];


    enum input input_method;
    const char *input_file;


    enum output output_method;
    const char *output_file;
} args;


extern int char_upper_case(int character);
extern int char_lower_case(int character);

extern size_t increment_count();

#endif
