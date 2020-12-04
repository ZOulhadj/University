"""

The purpose of the first program (Uber Fare) is to
calculate the total fare price based on the distance
a person travels. A function is used to calculate this
value and returned.

"""

# Uber rates (£)
base_rate = 2.50
mile_rate = 1.25

# distance (miles)
distance = 5

def total_fare(distance):
    """ Return the total fare price based on distance and mile rate """

    # ensure a negative value for a distance cannot be entered
    if distance < 0:
        raise ValueError("Distance must be greater than 0")


    # return calculation
    return base_rate + (mile_rate * distance)


# calculate fare price with a given distance
fare = total_fare(distance)

# output fare price
print("Total fare: " + "£{:,.2f}".format(fare))
