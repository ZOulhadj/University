import math

# 100, 000 hours
hours_of_content = 100000

# encoding time length for 1 hour of footage
# 720p, 1080p, 2160p
sd_encoding = 0.25
hd_encoding = 0.50
uhd_encoding = 1.0

# initial cost to setup a system
initial_cost = 0


running_cost = 5.0

def main():
    # calculate the total amount of encoding hours
    sd_encoding_hours = hours_of_content * sd_encoding
    hd_encoding_hours = hours_of_content * hd_encoding
    uhd_encoding_hours = hours_of_content * uhd_encoding


    # note: we multiply by 3 since there are 3 resolutions
    total_content_hours = hours_of_content * 3

    total_encoding_hours = sd_encoding_hours + hd_encoding_hours + uhd_encoding_hours


    # calculate the total cost of the system at 50% content completion

    half_content_hours = total_content_hours / 2
    half_encoding_hours = total_encoding_hours / 2

    # note: there are 2016 hours in 12 weeks
    # note: we ceil the number of system required as we
    # cannot have 'half' of a system.
    half_systems_count = math.ceil(half_encoding_hours / 2016)

    total_initial_cost = half_systems_count * initial_cost

    half_running_cost = (2016 * running_cost) * half_systems_count


    # The total cost for the system at 50%
    half_total_cost = total_initial_cost + half_running_cost




    # calculate the total amount of cost for 75%

    # note: find half of half_content_hours so that we can later that onto of it
    # to get the 75% value

    third_percent_hours = half_content_hours / 2
    third_encoding_hours = half_encoding_hours / 2

    third_systems_count = math.ceil(third_encoding_hours / 2016)

    third_running_cost = (2016 * running_cost) * third_systems_count

    third_total_cost = half_total_cost + third_running_cost




    # calculate the total amount of cost at 100%

    # note: 4704 is the amount of hours in 28 weeks...from 24 to 52 (year)
    final_systems_count = math.ceil(third_encoding_hours / 4704)

    final_running_cost = (4704 * running_cost) * final_systems_count

    final_total_cost = third_total_cost + final_running_cost





    # print the three mile stones

    print("50%: ", "£{:,.2f}".format(half_total_cost))
    print("The number of systems: ", half_systems_count)
    print("")

    print("75%: ", "£{:,.2f}".format(third_total_cost))
    print("The number of systems: ", third_systems_count)
    print("")

    print("100%: ", "£{:,.2f}".format(final_total_cost))
    print("The number of systems: ", final_systems_count)
    print("")


if __name__ == "__main__":
    main()
