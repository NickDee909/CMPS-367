/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Nick's Calculator in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <sstream>
#include <stdexcept>

// Function prototypes
float evaluateExpression(const std::string &expression);
float evaluateSimpleExpression(std::istringstream &iss);
float applyOperation(float a, float b, char op);
bool isOperator(const char c);
int getPrecedence(char op);

int main() {
    // Display a welcome message and available operations
    std::cout << "Welcome to Nick's Calculator in C++!" << std::endl;
    std::cout << "You can use the following operators in your expressions:" << std::endl;
    std::cout << "+ : Addition" << std::endl;
    std::cout << "- : Subtraction" << std::endl;
    std::cout << "* : Multiplication" << std::endl;
    std::cout << "/ : Division (note: cannot divide by zero)" << std::endl;
    std::cout << "^ : Exponentiation (Power)" << std::endl;
    std::cout << "Please enter expressions with spaces between numbers and operators." << std::endl << std::endl;

    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        std::cout << "Enter a problem to solve: ";
        std::string input;
        std::getline(std::cin, input);

        try {
            float result = evaluateExpression(input);
            std::cout << "The answer to this problem is: " << result << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
        }

        std::cout << "Would you like to solve another problem? (Y/N) ";
        std::cin >> cont;
        std::cin.ignore(); // Clear the newline character from the input buffer
        std::cout << std::endl;
    }

    std::cout << "Thank you for using Nick's Calculator!" << std::endl;
    return 0;
}

// Function definitions follow

float evaluateExpression(const std::string &expression) {
    std::istringstream iss(expression);
    return evaluateSimpleExpression(iss);
}

float evaluateSimpleExpression(std::istringstream &iss) {
    std::stack<float> values;
    std::stack<char> ops;
    float value;
    char op;

    while (iss >> value) {
        values.push(value);

        while (iss >> op && isOperator(op)) {
            if (!ops.empty() && getPrecedence(ops.top()) >= getPrecedence(op)) {
                float b = values.top(); values.pop();
                float a = values.top(); values.pop();
                char currOp = ops.top(); ops.pop();
                values.push(applyOperation(a, b, currOp));
            } else {
                ops.push(op);
                break;
            }
        }
    }

    while (!ops.empty()) {
        float b = values.top(); values.pop();
        float a = values.top(); values.pop();
        char currOp = ops.top(); ops.pop();
        values.push(applyOperation(a, b, currOp));
    }

    return values.top();
}

float applyOperation(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0.0f) throw std::runtime_error("Error: Division by zero.");
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::runtime_error("Invalid operation");
    }
}

bool isOperator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
