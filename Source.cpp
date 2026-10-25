//**
* @file Source.cpp
* @author Kenneth Cherry
* @date 2026 - 10 - 25
* @brief A banking simulation that interacts with Account and Customer objects.
* /

// AI was used to review the program's organization, documentation, and banking logic.

#include <iostream>
#include "Account.h"

using std::cin;
using std::cout;
using std::endl;

// Function prototypes
void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

// Menu options
const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Entry point for the banking application.
 *
 * Creates a Customer and Account object, displays the account
 * information, and processes deposits, withdrawals, and
 * close-of-business updates until the user chooses to quit.
 *
 * @return 0 to indicate that the program completed successfully.
 */
int main()
{
    // Create a customer and an account using the provided sample data.
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);

    account.printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        {
            double amount;

            cout << "Enter deposit amount: ";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.deposit(amount);
            }
            else
            {
                cout << "Invalid amount. Must be greater than 0." << endl;
            }

            break;
        }

        case WITHDRAWAL:
        {
            double amount;

            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.withdraw(amount);
            }
            else
            {
                cout << "Invalid amount. Must be greater than 0." << endl;
            }

            break;
        }

        case CLOSE_OF_BUSINESS:
        {
            account.closeOfBusiness();
            break;
        }
        }

        menuChoice = getMenuOption();
    }

    return 0;
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT && choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}