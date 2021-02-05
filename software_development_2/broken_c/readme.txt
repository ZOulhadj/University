==================
=== Bugs fixed ===
==================

> Main function
    - Both functons display() and run_menu() have the void return type
    and thus, I removed 'int choice' being equal to those functions.

    - Since the choice variable was already defined above the while loop
    I change the line 'int choice = display_menu()' to 'choice = display_menu()'.
    This made it so that we are not redefining the choice variable.

    - Added a 'return 0' statement to the end of the main function.

> Guess the number
    - To ensure the same number is not used when using the rand()
    function, I am calling the srand() function which generates a seed
    which rand() then uses.

    - Set an upper limit to rand() function using a modulo operator.

> Run menu
    - Added the break keyword within each case scope of the switch statement
    to ensure that once a specific case is finished it does not call the other
    functions within other cases.

    - Added a missing semicolon in the default case.

> Smallest number
    - Fixed the exception error bug by reimplementing the function due to better solution.
    See the features implemented section to find out why.

============================
=== Features implemented ===
============================

> Main/Misc
    - Changed the while loop to a do while loop so that we can first initialise the
    choice variable before comparing its value. This is often used throughout as we
    cant compare an expression before the user has given us a value to work with.

    - Added a macro for setting the max value limit when getting a random number.

    - Removed argument count and arguments from main function as parameters. This
    is because they were simply not used within this program.

    - Create a menu array which allows for a menu list to be easily updated. When
    printing the menu, a for loop is used and simply iterates over the list so that
    it prints every item.


> Get choice/input
    - Instead of using scanf I am using fgets together with strtol to accept input
    and to convert to a numerical value.

    - I completely re-implemented the input within this program. One function is used
    for multiple types. INT for most inputs and a single DOUBLE is required for temperature
    conversion. The function reads the input buffer, validates it and returns the
    required type based a return_type parameter.

> Guess the number
    - Changed the while loop to a do while loop so that we can first initialise the
    choice variable before comparing its value.

> Finding number
    - Instead of filling an array and looping through the array comparing
    numbers. I instead simplified it by comparing the numbers immediately
    and therefore, it is more efficient.

    - Smallest number and biggest number were combined into one function and can be swapped
    using the LOWEST and HIGHEST enum flags.

> Temperature conversion
   - Implemented both conversions.

> Number to English
    - Implmented this functionality using recursion