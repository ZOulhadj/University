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

    # Ask the user to input the year
    year = int(input("Enter a year: "))

    # TODO: Find out if there is a better way
    # to do this below


    # Find last two digits of the inputted year
    index = int(str(year)[-2])

    # If the last two digits are beyond the array
    # bounds then find out the last digit and that
    # will be the index position
    if index > 11:
        i = int(str(year)[-1])
        print(animals[i])
    else:
        print(animals[index])

if __name__ == "__main__":
    main()
