/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Nick's Calculator in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <limits>
#include <cmath>  // Include for std::isnan

// Define a struct to hold calculator state
struct CalculatorState {
    double num1, num2;
    char operation;
    char cont = 'y';
};

// Function to perform arithmetic operations
double calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                std::cout << "Error: Division by zero.\n";
                return 0; // Handle division by zero appropriately
            } else {
                return a / b;
            }
        default:
            std::cout << "Error: Operation not supported.\n";
            return std::numeric_limits<double>::quiet_NaN(); // Return NaN for unsupported operations
    }
}

void flushInputStream() {
    std::cin.clear(); // Clears any error flags that might be set
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the remaining input until the end of line
}

int main() {
    CalculatorState state;  // Declare an instance of CalculatorState

    do {
        std::cout << "Enter first number, operator, and second number (e.g., 1 + 1): ";
        if (!(std::cin >> state.num1 >> state.operation >> state.num2)) {
            std::cout << "Invalid input. Please enter correct values.\n";
            flushInputStream(); // Clear erroneous input from the stream
            continue; // Skip the current iteration and prompt again
        }

        double result = calculate(state.num1, state.num2, state.operation);
        if (!std::isnan(result)) { // Check if the result is not NaN
            std::cout << "Result: " << result << "\n";
        }

        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> state.cont;
        flushInputStream(); // Clear the newline character left in the input buffer
    } while (state.cont == 'y' || state.cont == 'Y');

    std::cout << "Thank you for using the calculator.\n";
    return 0;
}

