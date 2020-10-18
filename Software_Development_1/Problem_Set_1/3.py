"""

This program asks the user to input a year and based on their input
the program will determin which animal is associated with that year
according to the chinese calendar.

Notes:
The equation to determine the animal of a specific year is
(year - 2000) % 12. This would return the remainder.
In this program, the remainder is used as an index value
for the animals array.

"""


def main():
    animals = [
        "Dragon",
        "Snake",
        "Horse",
        "Sheep",
        "Monkey",
        "Rooster",
        "Pig",
        "Rat",
        "Ox",
        "Tiger",
        "Dog",
        "Hare"
    ]

    # Ensure the user inputs the correct value
    while True:
        try:
            # Ask the user to input the year
            year = int(input("Enter a year: "))

        except ValueError:
            print("Invalid input")
            continue

        else:
            break

    # Print the animal of the inputted year
    print(f"The animal of the year {year} is: ", animals[(year - 2000) % 12])


if __name__ == "__main__":
    main()
