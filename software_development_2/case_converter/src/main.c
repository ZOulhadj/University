#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

/*
 * The initial size given to the dynamic array. If more data is stored within
 * the array than the size set by `INITIAL_BUFFER_SIZE`, the array will double
 * in size to ensure the data can be allocated.
 */
#define INITIAL_BUFFER_SIZE 100

/*
 * Array structure that holds the character data together with the array size
 * and the number of elements used.
 */
struct array
{
    int *buffer;

    size_t used;
    size_t size;
};


/*
 * The following three structures are used within the arguments structure when
 * reading data in regards to arguments given by the user. This ensures a
 * organised structure can be defined once reading user data has completed which
 * subseqently allows for us to change how the program behaves depending on
 * which values are set.
 */
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
 * and most importantly the buffer which stores the characters. The struct
 * is made globally available within this source file as we dont need to
 * pass an extra argument to each function that uses it.
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
 * Initialises an int array of size `INITIAL_BUFFER_SIZE`.
 */
void initialise_array(struct array *a)
{
    a->buffer = malloc(INITIAL_BUFFER_SIZE * sizeof(int));
    a->used   = 0;
    a->size   = INITIAL_BUFFER_SIZE;
}

/*
 * Sets a new value within the array
 */
void insert_element(struct array *a, int element)
{
    // If all elements have been used up, create a new array which is double
    // in size and copy data into the new array
    if (a->used == a->size)
    {
        a->size  *= 2;
        a->buffer = realloc(a->buffer, a->size * sizeof(int));
    }

    // store element and increment a->used counter
    a->buffer[a->used++] = element;
}

/*
 * Clear the array from the heap and cleanup other values
 */
void free_array(struct array *a)
{
    free(a->buffer);
    a->buffer = NULL;
    a->used = 0;
    a->size = 0;
}


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


/*
 * Handles the users given arguments and initialises the `arguments` structure.
 */
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
                // if the next argument is not NULL and is not another argument
                // then read it as a input file
                if (arguments[i + 1] != NULL && arguments[i + 1][0] != '-')
                {
                    args.input_method = FILE_INPUT;
                    args.input_file = arguments[i + 1];
                }
                else
                {
                    // if no argument is provided after -i then input will be taken through the console
                    args.input_method = USER_INPUT;
                    args.input_file = NULL;
                }
               break;
            case 'o':
                // if the next argument is not NULL then set that file as the output
                if (arguments[i + 1] != NULL)
                {
                    args.output_method = FILE_OUTPUT;
                    args.output_file = arguments[i + 1];
                }
                else
                {
                    // if no output file is provided then print it onto the console
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


/*
 * Display the correct program usage in the event that a user provideds the
 * incorrect syntax.
 */
void display_syntax()
{
    printf("\n");

    printf("%s\n", "-[u/l] -c -i <optional_file> -o <optional_file>");
    printf("\n");
    printf("%s\n", "-u/l: uppercase/lowercase");
    printf("%s\n", "-c: count words (optional)");
    printf("%s\n", "-i: input file");
    printf("%s\n", "<optional_file>: optional input file");
    printf("%s\n", "-o: output file");
    printf("%s\n", "<optional_file>: optional output file");

    printf("\n");
}


/*
 * Read in the data given by the user either through a file or stdin.
 */
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

/*
 * This function is used to check if each character is within the alphabet
 */
bool is_alphabet(int code)
{
    // check if given code is within the alphabet
    return (code >= 'a' && code <= 'z') || (code >= 'A' &&  code <= 'Z');
}

/*
 * Convert the input data into a set case
 */
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


/*
 * Outputs the data using the method specified by the user
 */
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



int main(int argc, char **argv)
{
    // if no arguments are provived exit the program
    if (argc < 2)
    {
        display_syntax();

        return false;
    }

    // initialise buffer that will be used to store input data
    initialise_array(&args.array);

    // parse arguments
    bool parse = parse_arguments(argc, argv);
    if (!parse)
    {
        printf("Error: Failed parsing arguments!\n");
        display_syntax();

        return false;
    }

    // read data from the user
    bool data = read_data();
    if (!data)
    {
        printf("Error: Failed to read data!\n");
        return false;
    }

    // convert case
    convert_case();


    output_data();

    // remove buffer from heap
    free_array(&args.array);

    return 0;
}
