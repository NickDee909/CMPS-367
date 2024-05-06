/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: BMI Calculator in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <string>
#include <limits>

// Struct to hold all the person's data
struct Person {
    std::string name;
    int age;
    std::string gender;
    int heightFeet;
    int heightInches;
    int totalHeightInches;
    double weight;
    double bmi;
    std::string bmiMeaning;
};

// Function to calculate BMI and interpret it
void calculateBMI(Person& p) {
    p.totalHeightInches = (p.heightFeet * 12) + p.heightInches;
    p.bmi = (703 * p.weight) / (p.totalHeightInches * p.totalHeightInches);
    if (p.bmi < 18.5) p.bmiMeaning = "underweight";
    else if (p.bmi < 25) p.bmiMeaning = "normal weight";
    else if (p.bmi < 30) p.bmiMeaning = "overweight";
    else p.bmiMeaning = "obesity";
}

// Function to flush the input buffer
void flushInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Person user;

    // Collect user data
    std::cout << "Please enter your name: ";
    std::getline(std::cin, user.name);
    std::cout << "Please enter your age: ";
    std::cin >> user.age;
    flushInput();
    std::cout << "Please enter your Gender: ";
    std::getline(std::cin, user.gender);
    std::cout << "Please enter your height in feet: ";
    std::cin >> user.heightFeet;
    std::cout << "Please enter your height in inches: ";
    std::cin >> user.heightInches;
    std::cout << "Please enter your weight in pounds: ";
    std::cin >> user.weight;
    flushInput();

    // Process the responses
    calculateBMI(user);

    // Output the results
    std::cout << "Hi " << user.name << ",\n"
              << "You are a " << user.gender << ". You are " << user.age << " years old. "
              << "You are currently " << user.heightFeet << "’" << user.heightInches
              << " and you currently weigh " << user.weight << " pounds. "
              << "Your BMI is " << user.bmi << ", which is " << user.bmiMeaning << ".\n"
              << "Thank you for using the BMI Calculator.\n";

    return 0;
}
