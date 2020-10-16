from math import ceil


def main():
    # Input user data
    cost = float(input("Enter the cost of your future home: "))
    annual_salary = float(input("Enter you annual salary: "))
    savings_reserve = float(input("Enter the amount annual salary to be saved: "))

    # The amount of down payment for the house
    down_payment = (25.0 * cost) / 100.0

    # Monthly salary
    monthly_salary = annual_salary / 12

    # Check savings percentage
    monthly_savings = savings_reserve / 12

    # Calculate salary percentage
    salary_percentage = (monthly_savings / monthly_salary) * 100.0

    # If savings amount is greater than 10% of their monthly limit then set a 10% limit on savings
    savings_before_limit = None
    if salary_percentage > 10.0:
        print("A savings limit has been applied of 10% of your monthly salary")
        savings_before_limit = monthly_savings
        monthly_savings = (10.0 * monthly_salary) / 100.0

    # Calculate how long in months it will take to afford the down payment
    duration = ceil(down_payment / monthly_savings)

    # Output information
    print("It will take ", duration, " month(s) to save up for a down payment")
    print("")
    print("Cost of house: " + "£{:,.2f}".format(cost))
    print("Yearly salary: " + "£{:,.2f}".format(annual_salary))
    print("Down payment:  " + "£{:,.2f}".format(down_payment))
    print("Monthly salary: " + "£{:,.2f}".format(monthly_salary))
    print("Monthly savings: " + "£{:,.2f}".format(monthly_savings))
    print("Monthly savings (before 10% savings limit): " + "£{:,.2f}".format(savings_before_limit))


if __name__ == "__main__":
    main()
