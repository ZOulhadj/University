#ifndef _CASE_CONVERTER_H
#define _CASE_CONVERTER_H


#include <stdbool.h>

enum cases
{
    LOWER_CASE,
    UPPER_CASE,
    DEFAULT_CASE = UPPER_CASE
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


    char buffer[500];


    enum input input_method;
    const char *input_file;


    enum output output_method;
    const char *output_file;
};


/*
 * char_lower_case(int c)
 *
 * Description: An assembly implemented function that accepts a single parameter
 * of type integer (ascii character code) and coverts it to lower case.
 *
 * Note: Only alphabetical characters are converted.
 */
extern char char_lower_case(int c);


/*
 * char_upper_case(int c)
 *
 * Description: An assembly implemented function that accepts a single parameter
 * of type integer (ascii character code) and coverts it to upper case.
 *
 * Note: Only alphabetical characters are converted.
 */
extern char char_upper_case(int c);


bool parse_arguments(int argc, char **argv, struct arguments *args);

void display_syntax();

bool is_alphabet(int code);

void tolower_case(char *c);

void toupper_case(char *c);

bool read_file(const char *file_path, char *buffer);

void read_data(struct arguments *args);

bool output_data(struct arguments *args);

#endif
