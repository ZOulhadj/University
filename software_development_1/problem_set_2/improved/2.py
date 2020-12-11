"""

The second program is intended to print out a list of numbers
that are multiples of 7 going up to the inputted number. For
example, if the user enters 147 then the output would be
7, 14, 21, 28... etc. all the way to 147. The program sets
a minimum number limit of 100 so the user can only enter 101 or
greater.

"""


def main():
    # Ensure correct input is given by the user
    while True:
        # ask for a number by the user
        try:
            number = int(input("Enter a number greater than 100: "))

            if number <= 100:
                raise ValueError

            # break out of input loop
            break
        except ValueError:
            # if given input is invalid, print an error message
            print("Error: Please enter a valid integer value or a number greater than 100.")x

    # build a list of multiples of 7 for the given number
    # note: number + 7 ensures that the inputted number is counted as well
    multiples = range(7, number + 7, 7)

    # print all the multiples of 7
    for i in multiples:
        print(i)

if __name__ == "__main__":
    main()
