/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Multiplication table
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string name, gender;
    int age, heightFeet, heightInches, weightPounds;
    double inches, bmi;

    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);
    
    std::cout << "Please enter your age: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    
    std::cout << "Please enter your Gender (male/female): ";
    std::getline(std::cin, gender);
    
    std::cout << "Please enter your height in feet: ";
    std::cin >> heightFeet;
    
    std::cout << "Please enter your height in inches: ";
    std::cin >> heightInches;
    
    std::cout << "Please enter your weight in pounds: ";
    std::cin >> weightPounds;

    // Calculate total height in inches and BMI
    inches = (heightFeet * 12) + heightInches;
    bmi = (703 * static_cast<double>(weightPounds)) / (inches * inches);

    // Determine the meaning of the BMI
    std::string bmiCategory;
    if (bmi < 16) {
        bmiCategory = "Severe Thinness";
    } else if (bmi >= 16 && bmi < 17) {
        bmiCategory = "Moderate Thinness";
    } else if (bmi >= 17 && bmi < 18.5) {
        bmiCategory = "Mild Thinness";
    } else if (bmi >= 18.5 && bmi < 25) {
        bmiCategory = "Normal";
    } else if (bmi >= 25 && bmi < 30) {
        bmiCategory = "Overweight";
    } else if (bmi >= 30 && bmi < 35) {
        bmiCategory = "Obese Class I";
    } else if (bmi >= 35 && bmi < 40) {
        bmiCategory = "Obese Class II";
    } else {
        bmiCategory = "Obese Class III";
    }

    // Output the results
    std::cout << "Hi " << name << ",\n";
    std::cout << "You are a " << gender << ". You are " << age << " years old. ";
    std::cout << "You are currently " << heightFeet << "’" << heightInches << " and you currently weigh " << weightPounds << " pounds. ";
    std::cout << "Your BMI is " << bmi << ", which is considered " << bmiCategory << ".\n";
    std::cout << "Thank you for using the BMI Calculator." << std::endl;

    return 0;
}



