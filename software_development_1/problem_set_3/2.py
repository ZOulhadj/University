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

def main():

    # this variable will hold the currently inputted word
    word = None

    while word != "":
        # read a word from the user
        word = input("Enter a word: ")

        # output an error if inputted string does not contain only letters
        if not word.isalpha() and word != "":
            print("Error: Only strings are accepted")
            continue

        # if the inputted word is not already in the list then add it

        # This search is linear and therefore it has a complexity of
        # O(n) where n is the size of the list at that moment in time.
        if word not in words:
            words.append(word)


    print("")

    # output the unique inputted words
    for word in words:
         print(word)


if __name__ == "__main__":
    main()
