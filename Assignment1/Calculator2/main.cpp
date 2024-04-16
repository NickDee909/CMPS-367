/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Multiplication table
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

// Function declarations for clarity
double performOperation(const std::vector<std::string>& tokens);
double executeMathOperation(double operand1, double operand2, const std::string& operation);

int main() {
    std::string input;
    char continueCalculation = 'y';

    std::cout << "Welcome to the Advanced Math Calculator!" << std::endl;

    while (continueCalculation == 'y' || continueCalculation == 'Y') {
        std::cout << "Enter a mathematical expression to solve (e.g., sin(90), 5 + 3, max(10, 20)): ";
        getline(std::cin, input);

        // Tokenize the input for processing
        std::istringstream iss(input);
        std::vector<std::string> tokens(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>{});

        try {
            double result = performOperation(tokens);
            std::cout << "Result: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "Mathematics knows no races or geographic boundaries; for mathematics, the cultural world is one country." << std::endl;
        std::cout << "- David Hilbert" << std::endl;

        std::cout << "Do you want to calculate another expression? (Y/N): ";
        std::cin >> continueCalculation;
        std::cin.ignore(); // Clear newline character left in the input buffer
    }

    std::cout << "Thank you for using the Math Calculator!" << std::endl;
    return 0;
}

double performOperation(const std::vector<std::string>& tokens) {
    if (tokens.size() == 1) {
        throw std::invalid_argument("Insufficient data for operation.");
    }

    double operand1 = std::stod(tokens[0]), operand2 = tokens.size() > 2 ? std::stod(tokens[2]) : 0;
    std::string operation = tokens[1];

    return executeMathOperation(operand1, operand2, operation);
}

double executeMathOperation(double operand1, double operand2, const std::string& operation) {
    if (operation == "+") return operand1 + operand2;
    if (operation == "-") return operand1 - operand2;
    if (operation == "*") return operand1 * operand2;
    if (operation == "/") {
        if (operand2 == 0) throw std::invalid_argument("Division by zero is undefined.");
        return operand1 / operand2;
    }
    if (operation == "%") return static_cast<int>(operand1) % static_cast<int>(operand2);
    if (operation == "^") return std::pow(operand1, operand2);

    // Single operand functions
    if (operation == "sin") return std::sin(operand1);
    if (operation == "cos") return std::cos(operand1);
    if (operation == "tan") return std::tan(operand1);
    if (operation == "sqrt") return std::sqrt(operand1);
    if (operation == "ceil") return std::ceil(operand1);
    if (operation == "floor") return std::floor(operand1);
    if (operation == "abs") return std::abs(operand1);
    if (operation == "round") return std::round(operand1);
    if (operation == "log") return std::log(operand1);
    if (operation == "log10") return std::log10(operand1);
    if (operation == "log2") return std::log2(operand1);

    // Multi-operand functions
    if (operation == "max") return std::max(operand1, operand2);
    if (operation == "min") return std::min(operand1, operand2);
    if (operation == "atan2") return std::atan2(operand1, operand2);

    throw std::invalid_argument("Unsupported operation.");
}
