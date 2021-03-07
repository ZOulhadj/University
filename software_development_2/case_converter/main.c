#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "case_converter.h"

// TODO: If a certain case is specified make sure that case is ignored when that type
// of character is inputted
// TODO: Implement word count within assembly
// TODO: Add documentation for all functions
// TODO: Implement a dynamic buffer allocator? User could import a big file which would cause
// a buffer overflow if we have a limited buffer number.
bool parse_arguments(int argument_count, char **arguments)
{
    int i = 1;
    while (i < argument_count)
    {
        // parse arguments (i.e commands with a - infront) only
        if (arguments[i][0] == '-')
        {
            // fill arguments structure based on arguments given

            // cast argument letter into an ascii code
            int argument = (int)arguments[i][1];

            switch (argument)
            {
            case 'u':
                args.case_conversion = UPPER_CASE;
                break;
            case 'l':
                args.case_conversion = LOWER_CASE;
                break;
            case 'c':
                args.count = true;
                break;
            case 'i':
                if (arguments[i + 1] != NULL && arguments[i + 1][0] != '-')
                {
                    args.input_method = FILE_INPUT;
                    args.input_file = arguments[i + 1];
                }
                else
                {
                    args.input_method = USER_INPUT;
                    args.input_file = NULL;
                }
               break;
            case 'o':
                if (arguments[i + 1] != NULL)
                {
                    args.output_method = FILE_OUTPUT;
                    args.output_file = arguments[i + 1];
                }
                else
                {
                    args.output_method = USER_OUTPUT;
                    args.output_file = NULL;
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

void convert_case()
{
    // convert to specific case based on argument
    if (args.case_conversion == LOWER_CASE)
    {
        for (int i = 0; args.buffer[i] != '\0'; ++i)
        {
            // obtain the characters ascii code
            int character = args.buffer[i];

            // only convert case if character is an alphabet
            if (is_alphabet(character))
                args.buffer[i] = char_lower_case(character);
        }

    }
    else if (args.case_conversion == UPPER_CASE)
    {
        for (int i = 0; args.buffer[i] != '\0'; ++i)
        {
            // obtain the characters ascii code
            int character = args.buffer[i];

            // only convert case if character is an alphabet
            if (is_alphabet(character))
                args.buffer[i] = char_upper_case(character);
        }

    }
}


bool read_data()
{

    switch (args.input_method)
    {
    case FILE_INPUT:
    {
        FILE *file = fopen(args.input_file, "r");
        if (!file)
        {
            printf("%s\n", "Error: Failed loading input data from file");
            return false;
        }

        // read contents of file into buffer array
        int character, i = 0;
        while ((character = fgetc(file)) != EOF)
        {
            // store each character as an ascii code
            args.buffer[i] = character;
            ++i;
        }

        fclose(file);

        convert_case();

        break;
    }
    case USER_INPUT:
    {
        printf("%s", "Enter text: ");

        // since fgets only allows us to store into a char* array, we create
        // a temp char* buffer and then copy its contents to our struct
        // buffer by casting it into an int. Not great but it will do
        // for now.
        char buffer[MAX_BUFFER_SIZE];
        fgets(buffer, sizeof(buffer), stdin);

        for (int i = 0; buffer[i] != '\0'; ++i)
            args.buffer[i] = (int)buffer[i];

        convert_case();

        break;
    }
    };


    return true;
}


bool output_data()
{
    // output the data
    if (args.output_method == FILE_OUTPUT)
    {
        FILE *file = fopen(args.output_file, "w");

        if (!file)
        {
            printf("%s\n", "Error: Failed to write output file!");
            return false;
        }

        // write buffer into file
        for (int i = 0; args.buffer[i] != '\0'; ++i)
            fprintf(file, "%c", args.buffer[i]);

        fclose(file);
    }
    else if (args.output_method == USER_OUTPUT)
    {
        // print the converted text onto the console
        for (int i = 0; args.buffer[i] != '\0'; ++i)
        {
            printf("%c", args.buffer[i]);
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
    bool parse = parse_arguments(argc, argv);
    if (!parse)
    {
        printf("%s\n", "Error: Failed parsing arguments!");
        display_syntax();

        return 0;
    }

    // read data from the user (file or stdin)
    bool data = read_data();
    if (!data)
    {
        printf("%s\n", "Error: Failed to read data!");
        return 0;
    }
    // todo: check if valid data is set

    // Note: find out if outputting data can really return false
    bool output = output_data();
    if (!output)
    {
        printf("%s\n", "Error: Failed to output data!");
        return 0;
    }


    return 0;
}
