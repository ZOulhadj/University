#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "case_converter.h"
#include "array.h"

// TODO: Implement word count within assembly
// TODO: Add documentation for all functions
// TODO: Find out when certain functions are supposed to be in the header file

int main(int argc, char **argv)
{
    // if no arguments are provived exit the program
    if (argc < 2)
    {
        display_syntax();

        return false;
    }

    // set default arguments
    struct arguments args = {};
    args.count = false;

    initialise_array(&args.array);

    // parse arguments
    bool parse = parse_arguments(argc, argv);
    if (!parse)
    {
        printf("Error: Failed parsing arguments!\n");
        display_syntax();

        return false;
    }

    // read data from the user (file or stdin)
    bool data = read_data();
    if (!data)
    {
        printf("Error: Failed to read data!\n");
        return false;
    }


    // todo: check if valid data is set


    // convert case
    convert_case();

    // TODO: find out if outputting data can really return false
    output_data();

    // clean up
    free_array(&args.array);

    return 0;
}
