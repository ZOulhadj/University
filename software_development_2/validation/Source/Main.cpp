#include <iostream>
#include <fstream>
#include <regex>

struct User
{
    std::string name;
    std::string dob;
    std::string number;
    std::string postcode;
};

std::string GetInput(const std::string& message)
{
    std::string input;

    std::cout << message;
    std::getline(std::cin, input);

    return input;
}

std::string ProcessInput(const std::string& message, const std::regex& format)
{
    std::string input;

    // continue looping until regex validation passes
    do
    {
        input = GetInput(message);

    } while (!std::regex_match(input, format));

    return input;
}

void WriteUserData(std::fstream& file, const User& user)
{
    file << "Name:          " << user.name << "\n";
    file << "Date of Birth: " << user.dob << "\n";
    file << "Number:        " << user.number << "\n";
    file << "Postcode:      " << user.postcode << "\n";
    file << "\n";
}

int main()
{
    // regex expressions for each of the data fields
    std::regex nameFormat("(((\?=[A-Z](\\'|\\-|\\s))[A-Z](\\'|\\-|\\s)[A-Z][a-z]+|[A-Z][a-z]+(\\'|\\-|\\s)\?))+");
    std::regex dateFormat("[0-9]{4}\\/[0][1-9]\\/[0-3][0-9]|[0-9]{4}\\/[1][0-2]\\/[0-3][0-9]");
    std::regex numberFormat("[0](?=(\\D*\\d){10}\\D*)(?=[^\\s]*\\s?[^\\s]*)[\\d\\s]*");
    std::regex postcodeFormat("[A-Z]{1,2}[0-9]{1,2}\\s[0-9][A-Z]{2}");

    // create or read an existing file
    std::fstream file("output.txt", std::ios::in  |
                                    std::ios::out |
                                    std::ios::app |
                                    std::ios::ate);

    std::string input;
    do
    {
        User user = {};

        // Store all validated data into structure
        user.name     = ProcessInput("Enter your name: ",     nameFormat);
        user.dob      = ProcessInput("Enter your DOB: ",      dateFormat);
        user.number   = ProcessInput("Enter your number: ",   numberFormat);
        user.postcode = ProcessInput("Enter your postcode: ", postcodeFormat);

        // write user data to file
        WriteUserData(file, user);

        // ask the user if they would like to quit before writing
        input = GetInput("Enter `q` now to quit or any other key to continue: ");
    } while (input != "q");


    return 0;
}
