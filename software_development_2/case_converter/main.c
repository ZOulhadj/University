#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// TODO: If a certain case is specified make sure that case is ignored when that type
// of character is inputted

// external functions implemented in assembly
extern char char_lower_case(int c);
extern char char_upper_case(int c);

enum cases
{
    LOWER_CASE,
    UPPER_CASE,
    DEFAULT_CASE = UPPER_CASE
} ;

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

    enum input input_method;
    const char *input_file;

    enum output output_method;
    const char *output_file;
};


bool parse_arguments(int argc, char **argv, struct arguments *args)
{

    int i = 1;
    while (i < argc)
    {
        // parse arguments (i.e commands with a - infront) only
        if (argv[i][0] == '-')
        {
            // fill arguments structure based on arguments given
            int c = (int)argv[i][1];

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
                if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
                {

                    args->input_method = FILE_INPUT;
                    args->input_file = argv[i + 1];
                }
                else
                {
                    args->input_method = USER_INPUT;
                    args->input_file = NULL;
                }

                break;
            case 'o':
                if (argv[i + 1] != NULL)
                {
                    args->output_method = FILE_OUTPUT;
                    args->output_file = argv[i + 1];
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
    // obtain the chracters ascii code
    int ascii_code = (int)*c;

    // if character is not within the alphabet ignore conversion
    if (!is_alphabet(ascii_code))
        return;

    // convert to lower case
    *c = char_lower_case(ascii_code);
}

void toupper_case(char *c)
{
    // obtain the chracters ascii code
    int ascii_code = (int)*c;

    // if character is not within the alphabet ignore conversion
    if (!is_alphabet(ascii_code))
        return;

    // convert to lower case
    *c = char_upper_case(ascii_code);
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
    char buffer[500];

    int word_count = 0;

    // parse arguments
    bool parse = parse_arguments(argc, argv, &args);
    if (!parse)
    {
        printf("%s\n", "Error: Failed parsing arguments!");
        display_syntax();

        return 0;
    }


    if (args.input_method == FILE_INPUT)
    {
        FILE *file = fopen(args.input_file, "r");
        if (file)
        {

        }
    }
    else if (args.input_method == USER_INPUT)
    {

        printf("%s", "Enter text: ");
        fgets(buffer, sizeof(buffer), stdin);


        if (args.case_conversion == UPPER_CASE)
        {
            for (int i = 0; buffer[i] != '\0'; ++i)
            {
                toupper_case(&buffer[i]);

                // increment word count when a space is found
                if (buffer[i] == ' ')
                    ++word_count;
            }

        }
        else if (args.case_conversion == LOWER_CASE)
        {
            for (int i = 0; buffer[i] != '\0'; ++i)
            {
                tolower_case(&buffer[i]);

                // increment word count when a space is found
                if (buffer[i] == ' ')
                    ++word_count;
            }

        }

    }


    // output the data
    if (args.output_method == FILE_OUTPUT)
    {

    }
    else if (args.output_method == USER_OUTPUT)
    {
        // print the converted text onto the console
        for (int i = 0; buffer[i] != '\0'; ++i)
        {
            printf("%c", buffer[i]);
        }
    }

    return 0;
}
