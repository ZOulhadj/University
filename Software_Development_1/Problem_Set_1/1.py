from math import log10

# Program entry point
def main():
    # Ask the user to input two values
    x = int(input("Enter first integer number: "))
    y = int(input("Enter second integer number: "))

    # Sum of x and y
    sum = x + y
    print(f"The sum of {x} + {y}: ", sum)

    # Difference
    difference = abs(x - y)
    print(f"The difference between {x} and {y}: ", difference)

    # Product
    product = x * y
    print(f"The product of {x} and {y}: ", product)

    # Quotient
    # Check if second value is 0 to avoid an error
    if (y != 0):
        quotient = x / y
        print(f"The quotient of {x} divided by {y}: ", quotient)
    else:
        print("Cannot divide by zero")

    # Remainder
    remainder = x % y
    print("The remainder is: ", remainder)

    # Log
    if (x > 1):
        log = log10(x)
        print(f"The result of log10({x}): ", log)
    else:
        print("log10 cannot compute a negative number")

    # Power
    power = x**y
    print(f"{x} to the power of {y}: ", power)

if __name__ == "__main__":
    main()
