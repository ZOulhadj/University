"""

The final program calculates the total price for a group to
an amusement park. The user enters the ages of all their
group members. Then based on this list, the program
calculates the total admission fee.

"""


def main():
    guest_ages = []

    # Ensure correct input is given by the user
    while True:
        # ask for a number by the user
        try:
            while True:
                age = input("Enter a guest age: ")

                if age:
                    # add the guest add to the list and cast it to an integer
                    guest_ages.append(int(age))
                else:
                    # end input if no input is given
                    break

        except ValueError:
            # if given input is invalid, print an error message
            print("Error: Please enter a valid integer value.")
        else:
            # break out of loop if all input conditions have been met
            break

    # total admission price variable
    total = 0

    # variables to make it easier to update the prices in the future
    baby_fee = 0
    child_fee = 899.90
    elder_fee = 1490.49
    other_fee = 1999.99

    # calculate the price for the group
    for guest in guest_ages:
        if guest <= 3:
            baby_fee += 0 # or continue
        elif guest >= 4 and guest <= 11:
            total += child_fee
        elif guest >= 70:
            total += elder_fee
        else:
            total += other_fee

    # output the total admission fee
    print("The total admission fee is: " + "£{:,.2f}".format(total))

if __name__ == "__main__":
    main()
