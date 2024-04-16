/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Multiplication table
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    int startRange, endRange, startMultiplier, endMultiplier;
    char createAnother = 'y';

    std::cout << "Welcome to the Multiplication Table Generator!" << std::endl;

    do {
        std::cout << "Let's set up your multiplication table." << std::endl;

        // Prompt for the starting range for table rows
        std::cout << "Enter the smallest number you'd like to multiply (start of row range), for example, 1: ";
        while (!(std::cin >> startRange)) {
            std::cout << "Please make sure to enter a whole number for the start of the row range: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Prompt for the ending range for table rows
        std::cout << "Enter the largest number you'd like to multiply (end of row range), for example, 10: ";
        while (!(std::cin >> endRange)) {
            std::cout << "Please make sure to enter a whole number for the end of the row range: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Prompt for the starting range for table columns
        std::cout << "Now, enter the smallest number you'd like to use as a multiplier (start of column range), for example, 1: ";
        while (!(std::cin >> startMultiplier)) {
            std::cout << "Please make sure to enter a whole number for the start of the column range: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Prompt for the ending range for table columns
        std::cout << "And finally, enter the largest number you'd like to use as a multiplier (end of column range), for example, 5: ";
        while (!(std::cin >> endMultiplier)) {
            std::cout << "Please make sure to enter a whole number for the end of the column range: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Generate and print the multiplication table
        std::cout << "\nCreating a multiplication table from " << startRange
                  << " to " << endRange << " for multipliers from " << startMultiplier
                  << " to " << endMultiplier << ":\n\n";

        // Header row
        std::cout << "     "; // Spacing for alignment
        for (int i = startMultiplier; i <= endMultiplier; ++i) {
            std::cout << std::setw(4) << i;
        }
        std::cout << "\n"; // Newline for the start of the table rows

        // Table rows
        for (int i = startRange; i <= endRange; ++i) {
            std::cout << std::setw(4) << i << " |";
            for (int j = startMultiplier; j <= endMultiplier; ++j) {
                std::cout << std::setw(4) << i * j;
            }
            std::cout << "\n";
        }

        // Prompt to create another table
        std::cout << "\nWould you like to create another table? (Enter Y for Yes or N for No): ";
        std::cin >> createAnother;
        while (std::cin.fail() || (createAnother != 'Y' && createAnother != 'y' && createAnother != 'N' && createAnother != 'n')) {
            std::cout << "Invalid input. Please enter Y to create another table or N to exit: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> createAnother;
        }
        std::cout << "\n"; // Provide spacing before potentially restarting or exiting
    } while (createAnother == 'Y' || createAnother == 'Y');

    std::cout << "Thank you for using the Multiplication Table Generator. Goodbye!" << std::endl;
    return 0;
}


