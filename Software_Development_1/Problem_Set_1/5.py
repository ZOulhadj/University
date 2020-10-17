from math import ceil, floor

# TODO: Add a check to see if savings is greater than salary

def main():
    # Input valid user data
    while True:
        try:
            house_cost = float(input("Enter the cost of your future home: "))
            annual_salary = float(input("Enter you annual salary: "))
            savings_reserve = float(input("Enter the portion of salary to be saved: "))
        except ValueError:
            print("Sorry incorrect input. Please enter a numerical value.")
            continue
        else:
            break

    # Insert new line character to seperate input from output
    print("\n")

    # The amount of down payment based on house price
    down_payment = (25.0 * house_cost) / 100.0

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
        monthly_savings = (10.0 * monthly_salary) / 100.0

    # Calculate return of investments based on 0.04% of savings per month
    monthly_interest = (0.04 * monthly_savings) / 100.0

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
