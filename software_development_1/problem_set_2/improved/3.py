"""

The purpose of the program is to output if a given number is prime
or not. The program uses a function called is_prime() to return if
a given number is prime. If yes then the function returns True, else
it returns False. The return value of this function is then used to
display a given output.

"""


# function that returns True if num is prime and false if not
def is_prime(num):
    # prime numbers can only be 2 or above
    if num < 2:
        print("The smallest prime number is 2")
        return False

    # find out if number is prime or not
    for i in range(2, num):
        if (num % i) == 0:
            return False
    else:
        return True


def main():
    # Ensure correct input is given by the user
    while True:
        # ask for a number by the user
        try:
            number = int(input("Enter a number: "))

            # break out of input loop
            break
        except ValueError:
            # if given input is invalid, print an error message
            print("Error: Please enter a valid integer value.")

    # output if the inputted number is prime or not
    if is_prime(number):
        print(f"The number {number} is prime")
    else:
        print(f"The number {number} is not prime")

if __name__ == "__main__":
    main()
