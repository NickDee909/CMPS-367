/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Multiplication Table in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <iomanip> // For std::setw to format the output

struct MultiplicationRange {
    int tableStart;
    int tableEnd;
    int multiplyStart;
    int multiplyEnd;
};

void printMultiplicationTable(const MultiplicationRange& range) {
    std::cout << "Here is the multiplication table for "
        << range.multiplyStart << " to " << range.multiplyEnd
        << " in the range of " << range.tableStart << " to " << range.tableEnd << "\n";
    std::cout << std::setw(5) << "X";
    for (int j = range.multiplyStart; j <= range.multiplyEnd; ++j) {
        std::cout << std::setw(5) << j;
    }
    std::cout << "\n";

    for (int i = range.tableStart; i <= range.tableEnd; ++i) {
        std::cout << std::setw(5) << i;
        for (int j = range.multiplyStart; j <= range.multiplyEnd; ++j) {
            std::cout << std::setw(5) << i * j;
        }
        std::cout << "\n";
    }
}

int main() {
    MultiplicationRange range;
    char continueCreating = 'y';

    do {
        std::cout << "Enter the starting range for Multiplication Table: ";
        std::cin >> range.tableStart;
        std::cout << "Enter the ending range for Multiplication Table: ";
        std::cin >> range.tableEnd;
        std::cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
        std::cin >> range.multiplyStart;
        std::cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
        std::cin >> range.multiplyEnd;

        printMultiplicationTable(range);

        std::cout << "Do you want to create another multiplication table (y/n): ";
        std::cin >> continueCreating;
    } while (continueCreating == 'y' || continueCreating == 'Y');

    std::cout << "Thank you for using the multiplication table generator!\n";
    return 0;
}
