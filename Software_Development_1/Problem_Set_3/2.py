"""

The second program (Avoiding Duplicates) takes
a word as an input and stores it into a list.
For each word that the user inputs, the code checks
to see if that word already exists in the list. If
the word does not exist then that word is added.
When the user enters nothing, the programs exists.

"""

# declaration of the list that will contain all the unique words
words = []

# boolean flag
running = True


def validate_input(string):
    """ Validates the user input to only accepts characters and returns the word """

    # Ensure a user enters a valid string
    while True:
        word = input(string)

        # return early if nothing is entered
        if word == "":
            return ""

        # check if inputted string contains only letters
        elif not word.isalpha():
            print("Error: Only strings are accepted")
        else:
            break

    return word


while running:
    user_input = validate_input("Enter a word: ")

    # if the user enters nothing set the running flag to false
    if user_input == "":
        running = False

    # if the inputted word is not already in the list then add it

    # This search is linear and therefore it has a complexity of
    # O(n) where n is the size of the list at that moment in time.
    if user_input not in words:
        words.append(user_input)


print("")

# output the inputted word
for word in words:
    print(word)
