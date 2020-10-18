# Import required functions from module math
from math import ceil, floor


# This program calculates how long it would take to save up for a down payment.


# This function returns a value given a specified percentage
def find_percentage(percentage, value):
    return float((percentage * value) / 100)


def main():
    # Input valid user data
    while True:
        try:
            house_cost = float(input("Enter the cost of your future home: "))
            annual_salary = float(input("Enter you annual salary: "))
            savings_reserve = float(input("Enter the portion of salary to be saved: "))

            # Throw an error if savings is greater than annual salary
            if savings_reserve > annual_salary:
                print("ERROR: Annual savings is greater than annual salary")
                continue

        except ValueError:
            print("ERROR: Please enter a numerical value.")
            continue

        else:
            # If no errors occured then break out of loop
            break

    # Insert new line character to seperate input from output
    print("\n")

    # The amount of down payment based on house price
    down_payment = find_percentage(25, house_cost)

    # This sets how much will be saved per year in savings
    annual_savings = annual_salary - savings_reserve

    # Monthly salary
    monthly_salary = annual_salary / 12

    # Calculate savings amount per month
    monthly_savings = annual_savings / 12

    # Calculate savings percentage based on monthly salary
    savings_percentage = (monthly_savings / monthly_salary) * 100.0

    # If savings amount is greater than 10% of their monthly salary then set a 10% limit on savings
    savings_before_limit = None
    if savings_percentage > 10.0:
        savings_before_limit = monthly_savings

        # Set monthly savings to 10% of their monthly salary
        monthly_savings = find_percentage(10, monthly_salary)

    # Calculate return of investments based on 0.04% of savings per month
    monthly_interest = find_percentage(0.04, monthly_savings)

    # Add 0.04% of investment back into savings
    monthly_savings += monthly_interest

    # Calculate how long in months it will take to afford the down payment
    duration_months = down_payment / monthly_savings
    duration_days = ceil((duration_months % 1) * 30.417)



    # Output information
    print("It will take ", floor(duration_months), " month(s) and ", duration_days, " days to save up for the down payment")

    print("")

    print("Cost of house: " + "£{:,.2f}".format(house_cost))
    print("Yearly salary: " + "£{:,.2f}".format(annual_salary))
    print("Down payment for house: " + "£{:,.2f}".format(down_payment))
    print("Monthly salary: " + "£{:,.2f}".format(monthly_salary))
    print("Monthly savings: " + "£{:,.2f}".format(monthly_savings))

    print("")

    print("Monthly savings (before 0.04% added interest): " + "£{:,.2f}".format(monthly_savings - monthly_interest))

    # Only display monthly savings before if that applies
    if savings_before_limit:
        print("Monthly savings (before 10% savings limit): " + "£{:,.2f}".format(savings_before_limit))


if __name__ == "__main__":
    main()
