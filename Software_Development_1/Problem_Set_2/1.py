"""

This program asks the user to input an integer value. If the value
is positive then the program outputs a string indicating that it
is indeed positive. If however, the number is negative then the
program outputs that the number is negative. If the user enters
0 then the program jumps out of the input loop and subsequently
exits.

"""

def main():
    while True:

        # Ensure correct input is given by the user
        while True:
            # ask for a number by the user
            try:
                number = int(input("Enter a number (0 to quit): "))
            except ValueError:
                # if given input is invalid, print an error message
                print("Error: Please enter a valid integer value.")
            else:
                # break out of the input loop if the input value is valid
                break

        # exit the loop if number is 0
        if number == 0:
            break

        # If number is greater than 0 then it's positive else it's negative
        if number > 0:
            print(f"The number {number} is positive")
        else:
            print(f"The number {number} is negative")

if __name__ == "__main__":
    main()
