"""

This program asks the user to input the width and length
of a room in order to calculate the area.

"""


def main():
    # Ask the user to input the dimensions of the room
    width = float(input("Enter the width of the room in meters: "))
    length = float(input("Enter the length of the room in meters: "))

    # Display the area of the room with the correct symbole
    print("The area of the room is ", round(width * length, 2), "m\u00b2")


if __name__ == "__main__":
    main()
