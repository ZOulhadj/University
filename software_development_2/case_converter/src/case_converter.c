#include "case_converter.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool parse_arguments(int argument_count, char **arguments)
{
    // start count at 1 since index 0 is the program name
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
                args.word_count = 1;
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


bool read_data()
{
    if (args.input_method == FILE_INPUT)
    {
        FILE *file = fopen(args.input_file, "r");
        if (!file)
        {
            printf("%s\n", "Error: Failed loading input data from file");
            return false;
        }

        // read contents of file into buffer array
        int character;

        while ((character = fgetc(file)) != EOF)
            insert_element(&args.array, character);

        fclose(file);

        // set word count value
        if (args.count)
        {
            if (args.array.buffer[0] == '\n')
                args.word_count = 0;
        }
    }
    else if (args.input_method == USER_INPUT)
    {
        printf("%s", "Enter text: ");

        // since fgets only allows us to store into a char* array, we create
        // a temp char* buffer and then copy its contents to our struct
        // buffer by casting it into an int. Not great but it will do
        // for now.

        // TODO: Make this buffer dynamic
        char buffer[INITIAL_BUFFER_SIZE];

        fgets(buffer, sizeof(buffer), stdin);

        for (int i = 0; buffer[i] != '\0'; ++i)
            insert_element(&args.array, (int)buffer[i]);


        // set word count value
        if (args.count)
        {
            if (args.array.buffer[0] == '\n')
                args.word_count = 0;
        }

    }


    return true;
}


bool is_alphabet(int code)
{
    // check if given code is within the alphabet
    return (code >= 'a' && code <= 'z') || (code >= 'A' &&  code <= 'Z');
}

void convert_case()
{
    // convert to specific case based on argument
    if (args.case_conversion == UPPER_CASE)
    {
        for (int i = 0; args.array.buffer[i] != '\0'; ++i)
        {
            // obtain the characters ascii code
            int character = args.array.buffer[i];

            // only convert case if its a character
            // also check if the opposite case character is within the alphabet
            // to ensure that a captial letter is not converted
            if (is_alphabet(character) && is_alphabet(character - 32))
                args.array.buffer[i] = char_upper_case(character);

            // if a space if detected, increment the word count
            if (args.count && args.array.buffer[i] == ' ')
                args.word_count += increment_count();
        }
    }
    else if (args.case_conversion == LOWER_CASE)
    {
        for (int i = 0; args.array.buffer[i] != '\0'; ++i)
        {
            // obtain the characters ascii code
            int character = args.array.buffer[i];

            // only convert case if its a character
            // also check if the opposite case character is within the alphabet
            // to ensure that a lower case letter is not converted
            if (is_alphabet(character) && is_alphabet(character + 32))
                args.array.buffer[i] = char_lower_case(character);

            // if a space if detected, increment the word count
            if (args.count && args.array.buffer[i] == ' ')
                args.word_count += increment_count();
        }

    }
}



void output_data()
{
    // output the data
    if (args.output_method == FILE_OUTPUT)
    {
        FILE *file = fopen(args.output_file, "w");
        // todo: find out if writing a file could fail
        // maybe program does not have permision to write file?

        // write buffer into file
        for (int i = 0; args.array.buffer[i] != '\0'; ++i)
            fprintf(file, "%c", args.array.buffer[i]);

        if (args.count)
            printf("The total word count is: %lu\n", args.word_count);

        fclose(file);
    }
    else if (args.output_method == USER_OUTPUT)
    {
        // print the converted text onto the console
        for (int i = 0; args.array.buffer[i] != '\0'; ++i)
            printf("%c", args.array.buffer[i]);

        if (args.count)
            printf("The total word count is: %lu\n", args.word_count);
    }

}
