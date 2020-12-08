"""

The fifth program (Euclids Greatest Common Divisor) takes
two values can find outs the greatest common divisor. This
program uses the concept of recursion to effeciently 
find out the value.


"""

def greatest_common_divisor(a, b):
    """ Return the greatest common divisor for a and b """


    # if b is 0 then simply return a
    if b == 0:
        return a
    
    # find the remainder of a / b
    c = a % b
    
    # return itself (recursion)
    return greatest_common_divisor(b, c)


def main():
	gcd = greatest_common_divisor(252, 105)

	print("The greatest common divisor is", gcd)


if __name__ == "__main__":
	main()