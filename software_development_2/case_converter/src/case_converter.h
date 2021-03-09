#ifndef _CASE_CONVERTER_H
#define _CASE_CONVERTER_H

#include <stdbool.h>

#include "array.h"

enum cases
{
    UPPER_CASE,
    LOWER_CASE,
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


/*
 * The primary structure within the program that keeps track of the method
 * to input data, the case to be converted into, output method, word count
 * and most importantly the buffer which stores the characters
 */
struct arguments
{
    // case
    enum cases case_conversion;

    // counting
    bool count;
    size_t word_count;

    // buffer
    struct array array;

    // input
    enum input input_method;
    const char *input_file;

    // output
    enum output output_method;
    const char *output_file;
} args;


/*
 * Reads the given arguments by the user and initialises the arguments structure
 */
bool parse_arguments(int argument_count, char **arguments);


/*
 * Displays the program syntax onto the console
 */
void display_syntax();


/*
 * Reads the data from the user and stores it in memory for use
 */
bool read_data();


/*
 * Returns true or false depending on if the character given is within the
 * alphabet
 */
bool is_alphabet(int code);


/*
 * The primary function responsible for converting the data into
 * a specific case provided my the user as an argument
 */
void convert_case();


void output_data();


// External functions that are implemented within assembly

/*
 * This function converts a ascii character to upper case
 */
extern int char_upper_case(int character);


/*
 * This function converts a ascii character to lower case
 */
extern int char_lower_case(int character);

/*
 * Function returns one and can be used for incrementing a variable
 */
extern int increment_count();


#endif
