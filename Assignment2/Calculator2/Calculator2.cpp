/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Nick's Calculator 2 in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>  
#include <sstream>  

struct MathExpression {
    std::string operation;
    std::vector<double> numbers;
};

double performOperation(const MathExpression& expr) {
    const std::string& op = expr.operation;
    const auto& nums = expr.numbers;

    if (op == "+") return std::accumulate(nums.begin(), nums.end(), 0.0);
    if (op == "-") return std::accumulate(nums.begin() + 1, nums.end(), nums[0], std::minus<double>());
    if (op == "*") return std::accumulate(nums.begin(), nums.end(), 1.0, std::multiplies<double>());
    if (op == "/") {
        // Check for division by zero for all numbers after the first, as zero can be valid only as the first number if it is the numerator
        if (std::any_of(nums.begin() + 1, nums.end(), [](double n) { return n == 0; })) {
            throw std::invalid_argument("Division by zero");
        }
        return std::accumulate(nums.begin() + 1, nums.end(), nums[0], std::divides<double>());
    }
    if (op == "%") {
        if (nums[1] == 0) throw std::invalid_argument("Modulo by zero");
        return fmod(nums[0], nums[1]);
    }
    if (op == "^") return pow(nums[0], nums[1]);
    if (op == "sin") return sin(nums[0]);
    if (op == "asin") return asin(nums[0]);
    if (op == "cos") return cos(nums[0]);
    if (op == "acos") return acos(nums[0]);
    if (op == "tan") return tan(nums[0]);
    if (op == "atan") return atan(nums[0]);
    if (op == "atan2") {
        if (nums.size() < 2) throw std::invalid_argument("atan2 requires two arguments");
        return atan2(nums[0], nums[1]);
    }
    if (op == "sqrt") {
        if (nums[0] < 0) throw std::invalid_argument("sqrt of negative number");
        return sqrt(nums[0]);
    }
    if (op == "ceil") return ceil(nums[0]);
    if (op == "abs") return fabs(nums[0]); // Use fabs for absolute value of doubles
    if (op == "floor") return floor(nums[0]);
    if (op == "max") {
        if (nums.empty()) throw std::invalid_argument("max requires at least one argument");
        return *max_element(nums.begin(), nums.end());
    }
    if (op == "min") {
        if (nums.empty()) throw std::invalid_argument("min requires at least one argument");
        return *min_element(nums.begin(), nums.end());
    }
    if (op == "log") {
        if (nums[0] <= 0) throw std::invalid_argument("log of non-positive number");
        return log(nums[0]);
    }
    if (op == "log10") {
        if (nums[0] <= 0) throw std::invalid_argument("log10 of non-positive number");
        return log10(nums[0]);
    }
    if (op == "log2") {
        if (nums[0] <= 0) throw std::invalid_argument("log2 of non-positive number");
        return log2(nums[0]);
    }
    if (op == "round") return round(nums[0]);

    throw std::invalid_argument("Unsupported operation");
}

int main() {
    MathExpression expr;
    std::string input;
    double number;

    std::cout << "Welcome to Nick's 2nd Calculator! Enter the operation and numbers separated by space (e.g., '+ 2 3'): ";
    std::getline(std::cin, input);

    std::istringstream iss(input);
    iss >> expr.operation;

    while (iss >> number) {
        expr.numbers.push_back(number);
    }

    try {
        double result = performOperation(expr);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}

