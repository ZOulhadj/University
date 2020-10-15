def main():
    # Ask the user to input the dimensions of the room
    width = float(input("Enter the width of the room in meters: "))
    length = float(input("Enter the length of the room in meters: "))

    # Calculate area of room
    area = width * length

    # Display the area of the room with the correct
    print("The area of the room is ", area, "m\u00b2")

if __name__ == "__main__":
    main()
