#ifndef _CASE_CONVERTER_H
#define _CASE_CONVERTER_H

#include <stdbool.h>

#include "array.h"

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

    struct array array;

    enum input input_method;
    const char *input_file;


    enum output output_method;
    const char *output_file;
} args;

bool parse_arguments(int argument_count, char **arguments);


void display_syntax();

bool is_alphabet(int code);

void convert_case();

bool read_data();

void output_data();

extern int char_upper_case(int character);
extern int char_lower_case(int character);

extern int increment_count();

#endif
