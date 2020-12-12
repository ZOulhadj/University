"""

The third program (Roll the Dice) is responsible
for calculating and simulating the actual and expected
percentage of the total sum given by rolling two dice
a specific number of times.

Notes:
One of the key features of this program is that as a user,
you are able to change the individual settings for the program
such as the number of dice (number_of_dice) that be rolled
as well as the number of sides (number_of_sides) a dice has.

One of the main structures used is a tightly packed dictionary datatype that
looks as such:

    probabilities {
    |    [dice_roll_total] {
    |    |   ["Simulated"] {
    |    |   |   <simulated_value>
    |    |   },
    |    |   |
    |    |   ["Expected"] {
    |    |   |   <expected_value>
    |    |   }
    |    |},
    }

Please note that the total size of the dictionary will be
the total number of faces of the dice * number of dice
that can be obtained given the number of face and
die. For example, having 2 dice with 6 faces will give us a size of
12



"""

# import required modules
import random
import itertools

# main variables
simulation_count = 1000
number_of_dice = 2
number_of_sides = 6


max_roll_value = number_of_sides * number_of_dice
simulated_key = "Simulated"
expected_key = "Expected"

# generate a complete list of all possible combinations
combinations = list(itertools.product(
    [i for i in range(1, number_of_sides + 1)], repeat=number_of_dice))

# generate a dictionary to store values
probabilities = {}

# note: number_of_dice here is as the minimum expected result
for i in range(number_of_dice, max_roll_value + 1):
    # create a new dictionary for each number
    probabilities[i] = {}

    # for each number, create a sub-dictionary for simulated and expected values
    probabilities[i][simulated_key] = 0.0
    probabilities[i][expected_key] = 0.0


def roll_dice():
    """ Return the total sum of rolling two dice """

    # you cannot role a dice with 0 sides... thus, raise an error
    if number_of_sides < 1:
        raise ValueError("Number of dices must be greater than 0")


    # 'roll' the dice by generating a random number between 1 and 6
    total = 0
    for i in range(number_of_dice):
        total += random.randint(1, number_of_sides)

    # return the sum of the generated results
    return total


def simulate_rolls(roll_count):
    """ Simulate rolls and increase probability for a specific number """


    # calculate values
    for i in range(roll_count):
        # find out the sum of rolling two dice
        total = roll_dice()

        # for a given total score, increase that 'values' probability
        # by 0.1 which is (1 / roll_count) * 100. After all the rolls
        # this will total to the percentage that a specific score was
        # chosen
        probabilities[total][simulated_key] += (1 / roll_count) * 100


def expected_rolls():
    """ Calculate the expected probability (%) for each sum """


    # note: number_of_dice here is as the minimum expected result
    for dice_sum in range(number_of_dice, max_roll_value + 1):

        # if dice count is 2 or more then calculate combinations
        # else if count is 1 then simply return 1
        if number_of_dice > 1:
            count = 0
            for group in combinations:
                # find all the different possible combinations
                # that adds to our current number then increase the count
                if sum(group) == dice_sum:
                    count += 1

            total_combinations = count
        else:
            total_combinations = 1

        # calculate probility in % and store value in dictionary
        probability = (total_combinations / (number_of_sides**number_of_dice)) * 100
        probabilities[dice_sum][expected_key] += probability


def main():
    # call functions to perform simulation and expected calculations
    simulate_rolls(simulation_count)
    expected_rolls()


    print("|-----------+-------------------+------------------|")
    print("|   Total   |   Simulated (%)   |   Expected (%)   |")
    print("|-----------+-------------------+------------------|")

    # loop through the dictionary to output its values
    for dice_total in probabilities.keys():

        # print a pipe at the start of each row
        print("|", end="")

        # get stored values from dictionary
        simulated_value = probabilities[dice_total][simulated_key]
        expected_value = probabilities[dice_total][expected_key]

        # print out the actual values along with the appropriate formatting
        print("{:^11}".format(dice_total), end="|")
        print("{:^19,.2f}".format(float(simulated_value)), end="|")
        print("{:^18,.2f}".format(float(expected_value)), end="|\n")

        # print the bottom bar for each row
        print("|-----------+-------------------+------------------|")


if __name__ == "__main__":
    main()
