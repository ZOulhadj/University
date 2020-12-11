"""

This program generates 6 random numbers and then outputs them
in ascending order.

"""

import random

def main():
    # declare a set that will contain the 6 unique numbers
    numbers = set()

    while len(numbers) < 6:
        # generate a random number between 1 and 59
        number = random.randint(1, 59 + 1)

        # add the random number to the list if it does not exist
        numbers.add(number)

    # sort the set
    # note: the data type of the numbers set changes to a list
    numbers = sorted(numbers)

    # print the numbers
    for number in numbers:
        print(number, end=" ")

if __name__ == "__main__":
    main()
