#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "case_converter.h"

// TODO: If a certain case is specified make sure that case is ignored when that type
// of character is inputted
// TODO: Implement word count within assembly
// TODO: Add documentation for all functions
// TODO: Fix syntax error within switch statment

bool parse_arguments(int argument_count, char **arguments, struct arguments *args)
{
    int i = 1;
    while (i < argument_count)
    {
        // parse arguments (i.e commands with a - infront) only
        if (arguments[i][0] == '-')
        {
            // fill arguments structure based on arguments given
            int c = (int)arguments[i][1];

            switch (c)
            {
            case 'u':
                args->case_conversion = UPPER_CASE;
                break;
            case 'l':
                args->case_conversion = LOWER_CASE;
                break;
            case 'c':
                args->count = true;
                break;
            case 'i':
                if (arguments[i + 1] != NULL && arguments[i + 1][0] != '-')
                {

                    args->input_method = FILE_INPUT;
                    args->input_file = arguments[i + 1];
                }
                else
                {
                    args->input_method = USER_INPUT;
                    args->input_file = NULL;
                }

                break;
            case 'o':
                if (arguments[i + 1] != NULL)
                {
                    args->output_method = FILE_OUTPUT;
                    args->output_file = arguments[i + 1];
                }
                else
                {
                    args->output_method = USER_OUTPUT;
                    args->output_file = NULL;
                }

                break;
            default:
                return false;
            };
        }

        ++i;
    }


    return true;
}


void display_syntax()
{
    printf("\n");

    printf("%s\n", "-[u/l] -c -i <optional_file> -o <optional_file>");

    printf("%s\n", "-u/l: uppercase/lowercase");
    printf("%s\n", "-c: count words (optional)");
    printf("%s\n", "-i: input file");
    printf("%s\n", "<optional_file>: optional input file");
    printf("%s\n", "-o: output file");
    printf("%s\n", "<optional_file>: optional output file");

    printf("\n");
}


bool is_alphabet(int code)
{
    // check if given code is within the alphabet
    return (code >= 'a' && code <= 'z') || (code >= 'A' &&  code <= 'Z');
}


void tolower_case(char *c)
{
    // obtain the characters ascii code
    int ascii_code = (int)*c;

    // if character is not within the alphabet ignore conversion
    if (!is_alphabet(ascii_code))
        return;

    // convert to lower case
    *c = char_lower_case(ascii_code);
}


void toupper_case(char *c)
{
    // obtain the characters ascii code
    int ascii_code = (int)*c;

    // if character is not within the alphabet ignore conversion
    if (!is_alphabet(ascii_code))
        return;

    // convert to lower case
    *c = char_upper_case(ascii_code);
}


bool read_file(const char *file_path, char *buffer)
{
    FILE *file = fopen(file_path, "r");

    if (!file)
        return false;

    // read contents of file into buffer array
    int c, i = 0;
    while ((c = fgetc(file)) != EOF)
    {
        buffer[i] = (char)c;
        ++i;
    }

    return true;
}


void read_data(struct arguments *args)
{

    switch (args->input_method)
    {
    case FILE_INPUT:
        bool data = read_file(args->input_file, args->buffer);
        if (!data)
        {
            printf("%s\n", "Error: Failed loading input data from file");
            return;
        }

        if (args->case_conversion == UPPER_CASE)
        {
            for (int i = 0; args->buffer[i] != '\0'; ++i)
                toupper_case(&args->buffer[i]);

        }
        else if (args->case_conversion == LOWER_CASE)
        {
            for (int i = 0; args->buffer[i] != '\0'; ++i)
                tolower_case(&args->buffer[i]);

        }

        break;

    case USER_INPUT:
        printf("%s", "Enter text: ");
        fgets(args->buffer, sizeof(args->buffer), stdin);


        if (args->case_conversion == UPPER_CASE)
        {
            for (int i = 0; args->buffer[i] != '\0'; ++i)
                toupper_case(&args->buffer[i]);

        }
        else if (args->case_conversion == LOWER_CASE)
        {
            for (int i = 0; args->buffer[i] != '\0'; ++i)
                tolower_case(&args->buffer[i]);

        }

        break;
    };

}


bool output_data(struct arguments *args)
{
    // output the data
    if (args->output_method == FILE_OUTPUT)
    {
        FILE *file = fopen(args->output_file, "w");

        if (!file)
        {
            printf("%s\n", "Error: Failed to write output file!");
            return false;
        }

        // write buffer into file
        for (int i = 0; args->buffer[i] != '\0'; ++i)
        {
            fprintf(file, "%c", args->buffer[i]);
        }
    }
    else if (args->output_method == USER_OUTPUT)
    {
        // print the converted text onto the console
        for (int i = 0; args->buffer[i] != '\0'; ++i)
        {
            printf("%c", args->buffer[i]);
        }


        // TODO: print the total word count
    }

    return true;
}


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
    args.case_conversion = DEFAULT_CASE;
    args.count = false;


    // parse arguments
    bool parse = parse_arguments(argc, argv, &args);
    if (!parse)
    {
        printf("%s\n", "Error: Failed parsing arguments!");
        display_syntax();

        return 0;
    }

    // read data from the user (file or stdin)
    read_data(&args);

    // todo: check if valid data is set

    // Note: find out if outputting data can really return false
    bool output = output_data(&args);
    if (!output)
    {
        printf("%s\n", "Error: Failed to output data!");
        return 0;
    }


    return 0;
}
