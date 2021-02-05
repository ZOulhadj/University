#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Sets the buffer length that is used to store and read input data
#define INPUT_BUFFER_MAX    10

// Used to control the maximum number possible when generating a random number
#define RANDOM_MAX          100

// sets the limit on the number of values a user enters when finding a number for both smallest
// and largest
#define FIND_COUNT          10

/*
 * The input type enum along with the input struct work together to allow the same function
 * to be used when accepting user input. Instead of the input function returning a specific data type
 * it returns the input structure and based on the input_type that the function caller expects
 * then that will be the type that will be filled in memory since unions shares memory across the
 * different variables. Too bad C never got templates... :-(
 */
enum input_type
{
    INT, DOUBLE
};

struct input
{
    union
    {
        int    i;
        double d;
    };
};


/*
 * A list for the menu which in this specific case contains each of the mini-programs
 */
char *menu[] =
{
    "Guessing game",
    "Temperature conversion",
    "Find smallest",
    "Find largest",
    "Number to English",
};

/*
 * unique and tens are two arrays that store the english words for different numbers and are used
 * for printingl
 */
char *unique[20] =
{
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eightteen",
    "nineteen"
};

char *tens[10] =
{
    "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

enum find_type
{
    LOWEST,
    HIGHEST
};

/*
 * The first two functions below are helper functions that are used within the main programs.
 * These being get_input which is used to get safe input and convert which is used to convert a
 * value and prints out a english version of it.
 */

/*
 * Asks the user for input and returns an input struct that contains the value
 * in the associated type within the union.
 */
struct input get_input(const char *string, enum input_type return_type)
{
    char buffer[INPUT_BUFFER_MAX];

    bool valid_input;

    do {
        // Set an initial state for the valid input boolean flag
        valid_input = true;

        printf("%s", string);

        char *input = fgets(buffer, sizeof(buffer), stdin);

        /*
         * Here we check if a new line character exists within the input buffer.
         * If yes, then set that character to be a end of line character. This
         * allows us to then loop through the buffer later to ensure each character
         * is a valid input. However, if no newline character is detected, this means
         * that the user has inputted more characters that there is space within the input
         * buffer. This results in the left over input being stored in the stdin stream.
         * We clear this stream to ensure that other calls to fgets within the program later on
         * do not get automatically processed due to the stdin stream.
         */
        if (input)
        {
            char *c = strchr(buffer, '\n');
            if (c)
            {
                *c = 0;
            }
            else
            {
                // clear upto newline character
                scanf("%*[^\n]");
                scanf("%*c");
            }
        }

        /*
         * Here we loop through the input buffer until we read an end of line character.
         * If at any point we detect that a digit is not a valid integer, a boolean flag
         * is set to false and the input process is restarted. This ensures that only a
         * valid integer input is accepted.
         */
        for (int i = 0; buffer[i] != '\0'; ++i)
        {
            if (!isdigit(buffer[i]))
            {
                // TODO: Small exception for double values using decimal place
                if (buffer[i] == '.')
                    break;

                printf("Invalid digit detected! Please try again.\n");
                printf("\n");

                valid_input = false;
                break;
            }
        }

    } while (!valid_input);


    /*
     * Return the specific type as specified by the parameter return_type
     */
    struct input input = {};
    if (return_type == INT)
        input.i = (int)strtol(buffer, NULL, 0);
    else if (return_type == DOUBLE)
        input.d = strtod(buffer, NULL);

    return input;
}

/*
 * The convert function is a recursive function that takes in a number and prints
 * out the english equivalent. This is to be used within the number_to_english
 * function.
 */
void convert(int number)
{
    if(number >= 1000)
    {
        convert(number / 1000);
        printf("thousand");

        if(number % 1000)
        {
            if(number % 1000 < 100)
                printf(" and ");

            convert(number % 1000);
        }
    }
    else if(number >= 100)
    {
        convert(number / 100);
        printf("hundred");
        if(number % 100)
        {
            printf(" and ");
            convert (number % 100);
        }
    }
    else if(number >= 20)
    {
        char *tens_value = tens[number / 10];
        printf("%s", tens_value);

        if(number % 10)
        {
            printf(" ");
            convert(number % 10);
        }
    }
    else
    {
        printf("%s ", unique[number]);
    }
}



/*
 * Prints a main menu to the users screen given a menu title and list
 * of items to print.
 */
void display_menu(const char *title, char *list[])
{
    printf("%s\n", title);

    // Print a title and list seperator the length of the title string
    for (int i = 0; i < strlen(title); ++i)
        printf("-");

    printf("\n");


    // get the size of the menu list array
    int menu_item_count = sizeof(menu) / sizeof(menu[0]);

    // Print each menu item
    for (int i = 0; i < menu_item_count; ++i)
        printf("%d. %s\n", i + 1, list[i]);

    printf("0. Exit\n");
}

/*
 * Generates a random number which the user has to
 * guess.
 */
void guess_the_number()
{
    // Generates a random number between 0 and [RANDOM_MAX]
    int number = rand() % RANDOM_MAX;

    struct input guess;

    // Ask the student to guess the number
    do {
        guess = get_input("Enter number (0 to 100): ", INT);

        // Print an error if the user enters a number higher than the max value.
        if (guess.i > RANDOM_MAX)
        {
            printf("Error. The maximum possible value is %d\n", RANDOM_MAX);
            continue;
        }

        if (guess.i < number)
            printf("Too low!\n");
        else if (guess.i > number)
            printf("Too high!\n");

    } while (guess.i != number);

    printf("\n");
    printf("Well done!\n");
    printf("\n");
}

/*
 * Converts temperatues between C and F
 */
void temperature_conversion()
{
    printf("Conversion Menu\n");
    printf("===============\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("0. Exit\n");


    printf("\n");

    struct input choice = get_input("Enter choice: ", INT);

    printf("\n");


    struct input temperature = {};
    switch (choice.i)
    {
        case 1:
            temperature = get_input("Enter the temperature: ", DOUBLE);
            printf("%.2f F is %.2f in C\n", temperature.d, (temperature.d - 32) * 5 / 9);
            break;
        case 2:
            temperature = get_input("Enter the temperature: ", DOUBLE);
            printf("%.2f C is %.2f F\n", temperature.d, (temperature.d * 9 / 5) + 32);
            break;
        case 0:
            printf("Ok\n");
            break;
        default:
            printf("Not a valid menu item. Please try again\n");
            break;

    }
}

/*
 * Finds a number and prints it after user input based on if its the LOWEST or
 * HIGHEST number.
 */
void find_number(enum find_type type)
{
    // Ask user to enter an initial number
    struct input number = get_input("Enter a number: ", INT);


    for (int i = 1; i < FIND_COUNT; ++i)
    {
        struct input num = get_input("Enter a number: ", INT);

        // Note: There is no need to constantly check type since it will stay the same. Need to find a
        // better way of doing this... Or could just seperate low and high into different functions.
        if (type == LOWEST)
        {
            if (num.i < number.i)
                number.i = num.i;
        }
        else if (type == HIGHEST)
        {
            if (num.i > number.i)
                number.i = num.i;
        }
    }

    if (type == LOWEST)
        printf("The smallest number is: %d\n", number.i);
    else if (type == HIGHEST)
        printf("The highest number is: %d\n", number.i);
}

/*
 * Converts a numberic input to english
 */
void number_to_english()
{
    struct input number = get_input("Enter a number: ", INT);

    // convert number into a char array. This makes our life easier.
    char buffer[50];
    snprintf(buffer, 50, "%d", number.i);

    // Prevent a number being 10,000 or above being inputted as it's not supported
    if (number.i >= 10000)
    {
        printf("Sorry 9999 is the maximum number supported. Please try again\n");
        return;
    }

    // store the value in a unique variable as the number will change due to recursion
    int value = number.i;

    // call function that will print out the english version of the inputted number
    convert(number.i);

    printf("\n");
}

/*
 * The function runs the specific mini-programs (functions) based on the choice the user
 * has chosen.
 */
void run_menu(int choice)
{
    switch (choice)
    {
        case 1:
            guess_the_number();
            break;
        case 2:
            temperature_conversion();
            break;
        case 3:
            find_number(LOWEST);
            break;
        case 4:
            find_number(HIGHEST);
            break;
        case 5:
            number_to_english();
            break;
        case 0:
            printf("%s\n", "Goodbye!");
            break;
        default:
            printf("%s\n", "Error. Enter a number between 0 and 5.");
            break;
    }
}

// Main entry point of program
int main()
{
    // Use current time as seed for random generator
    srand(time(NULL));

    struct input choice;

    do {
        printf("\n");

        display_menu("Main menu", menu);

        printf("\n");

        choice = get_input("Enter choice: ", INT);

        printf("\n");

        run_menu(choice.i);

    } while (choice.i != 0);

    return 0;
}