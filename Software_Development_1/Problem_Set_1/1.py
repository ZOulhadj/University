from math import log10

"""

This program prints the result of various operations
between two numbers which the user inputs.

Notes:
Initially, each operation was stored in a variable and
passed as a paramter to the print function. However, to
increase the efficiency of the program, each calculation
is performed directly in the print function as this does
two things. Firstly, this saves memory as a variable does
not need to be alloacted on the stack and secondly, this
eliminates the need for the program to reference a specific
variable memory address since the value is passed into the
print function directly.

"""

def main():
    # Ask the user to input two integer values
    x = int(input("Enter first integer number: "))
    y = int(input("Enter second integer number: "))

    # Sum
    print(f"The sum of {x} + {y}: ", x + y)

    # Difference using absolute value
    print(f"The difference between {x} and {y}: ", abs(x - y))

    # Product
    print(f"The product of {x} and {y}: ", x * y)

    # Quotient
    # Avoid division by zero
    if (y > 0):
        print(f"The quotient of {x} divided by {y}: ", x / y)
    else:
        print("Cannot divide by zero")

    # Remainder
    print("The remainder is: ", x % y)

    # Log
    if (x > 1):
        print(f"The result of log10({x}): ", log10(x))
    else:
        print("log10 cannot compute a zero or negative number")

    # Power
    print(f"{x} to the power of {y}: ", x**y)


if __name__ == "__main__":
    main()
