/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Birthday Generator in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <string>
#include <limits>

// Function prototypes
std::string getMonthMeaning(int month);
std::string getDayMeaning(int day);
std::string getYearMeaning(int year);

int main() {
    std::string continueGame;
    int month, day, year;

    std::cout << "Welcome to Birthday Date Meaning Generator!" << std::endl;

    do {
        std::cout << "Please enter the month of your birthday (1-12): ";
        std::cin >> month;

        std::cout << "Please enter the day of your birthday (1-31): ";
        std::cin >> day;

        std::cout << "Please enter the year of your birthday: ";
        std::cin >> year;

        // Clear the newline character from the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Display meanings
        std::cout << "The month of " << getMonthMeaning(month) << std::endl;
        std::cout << "The " << day << " of the month means " << getDayMeaning(day) << std::endl;

        if (year >= 2000 && year <= 2023) {
            std::cout << "The year of " << year << " means that " << getYearMeaning(year) << std::endl;
        } else if (year < 2000) {
            std::cout << "Born before the year 2000? You are vintage and wise!" << std::endl;
        } else {
            std::cout << "The year of " << year << " is not within the valid range." << std::endl;
        }

        // Ask if the user wants to enter another birthday
        std::cout << "Would you like to try another one? (Y/N) ";
        std::cin >> continueGame;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    } while (continueGame == "Y" || continueGame == "y");

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}

std::string getMonthMeaning(int month) {
    switch (month) {
        case 1: return "January means Janus";
        case 2: return "February means Februa";
        case 3: return "March means Mars";
        case 4: return "April means Aphrodite";
        case 5: return "May means Maia";
        case 6: return "June means Juno";
        case 7: return "July means Julius Caesar";
        case 8: return "August means Augustus Caesar";
        case 9: return "September means the seventh month";
        case 10: return "October means the eighth month";
        case 11: return "November means the ninth month";
        case 12: return "December means the tenth month";
        default: return "Invalid month";
    }
}

std::string getDayMeaning(int day) {
    if (day < 1 || day > 31) return "Invalid day";
    return "has a unique significance";  // Placeholder for specific day meanings
}

std::string getYearMeaning(int year) {
    switch (year) {
        case 2000: return "you are a Millennial";
        case 2001: return "you are at the start of the new millennium";
        // Add other cases as necessary
        case 2023: return "you are in the present year";
        default: return "an interesting year";
    }
}


