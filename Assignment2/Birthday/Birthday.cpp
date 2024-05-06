/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Birthday in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <string>

struct Birthday {
    int month;
    int day;
    int year;
};

// Function to print the meaning based on the month
void printMonthMeaning(int month) {
    switch (month) {
    case 1: std::cout << "The month of January means Janus\n"; break;
    case 2: std::cout << "The month of February means Februa\n"; break;
        // Add other months...
    default: std::cout << "No specific meaning for this month.\n"; break;
    }
}

// Function to print the meaning based on the day
void printDayMeaning(int day) {
    switch (day) {
    case 1: std::cout << "The 1st of the month means Self-Started\n"; break;
    case 2: std::cout << "The 2nd of the month means Dualism\n"; break;
        // Add other days...
    default: std::cout << "No specific meaning for this day.\n"; break;
    }
}

// Function to print the meaning based on the year
void printYearMeaning(int year) {
    switch (year) {
    case 2000: std::cout << "The year 2000 means that you are a millennial\n"; break;
    case 2001: std::cout << "The year 2001 means new beginnings\n"; break;
        // Add other years...
    default: std::cout << "No specific meaning for this year.\n"; break;
    }
}

void inputAndPrintMeanings() {
    Birthday bd;
    char another = 'y';

    do {
        std::cout << "Please enter the month of your birthday (1-12): ";
        std::cin >> bd.month;
        std::cout << "Please enter the day of your birthday (1-31): ";
        std::cin >> bd.day;
        std::cout << "Please enter the year of your birthday (2000-2023): ";
        std::cin >> bd.year;

        std::cout << "\n";
        printMonthMeaning(bd.month);
        printDayMeaning(bd.day);
        printYearMeaning(bd.year);

        std::cout << "Would you like to try another one? (y/n): ";
        std::cin >> another;
        std::cout << "\n";
    } while (another == 'y' || another == 'Y');

    std::cout << "Thanks for playing!\n";
}

int main() {
    std::cout << "Welcome to Birthday Date Meaning Generator!\n";
    inputAndPrintMeanings();
    return 0;
}
