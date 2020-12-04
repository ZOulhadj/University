"""

The fifth program (Euclids Greatest Common Divisor) takes
two values can find outs the greatest common divisor. This
program uses the concept of recursion to effeciently
find out the value.


"""

def greatest_common_divisor(a, b):
    """ Return the greatest common divisor for a and b """

    # output the current values of a and b
    print(f"a is {a} and b is {b}")

    # if a is 0 then simply return the second parameter
    if a == 0:
        return b

    # call itself (recursion) and perform a modulo opertion
    return greatest_common_divisor(b % a, a)


gcd = greatest_common_divisor(22345, 55432)

print("")
print("The greatest common divisor is", gcd)
