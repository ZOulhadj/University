# This program prints the mutiplication table from 1 up to 10.

def main():

    # Print each column number
    for x in range(10):
        if x == 0:
            print("{:>6}".format(x + 1), end=" ")
        else:
            print("{:>2}".format(x + 1), end=" ")

    print("")

    for x in range(10):
        # Print row number
        print("{:>2}".format(x + 1), end="  ")

        # For each row print column numbers
        for y in range(10):
            print("{:>2}".format((x+1) * (y+1)), end=" ")

        print("")


if __name__ == "__main__":
    main()
