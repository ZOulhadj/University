"""

The fourth program (Merge Two Files) reads the contents
of two text files. It then merges them together and outputs
the combined result into a third file.



Note: As an example, I have made use of function
hints (PEP 484) to indicate the function return
type. This can be quite beneficial when reading
files as this allows a developer to know what kind
of buffer data we are reading.

"""


import os 


def read_file(filename) -> str:
    """ Read the contents of a file and return contents """
    
    with open(filename, 'r') as file:
        buffer = file.read()
        
    return buffer


def write_file(filename, buffer) -> None:
    """ Write contents to a file """

    with open(filename, 'w') as file:
        file.write(buffer)


def main():
	# read the contents of both files and store into a buffer variable
	buffer = read_file("file1.txt") + read_file("file2.txt")

	# write the contents of both files into a new file named file3.txt
	write_file("file3.txt", buffer)

	# print the combined text of file1 and file2 instead of reading the contents
	# of the newly created file3.txt. This is much more efficient as the data is
	# already in memory
	print(buffer)


if __name__ == "__main__":
	main()