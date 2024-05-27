# Shape Hierarchy Program

## Overview

The Shape Hierarchy Program is a simple console-based application that calculates the area and perimeter of various geometric shapes. This program is designed for educational purposes to demonstrate basic C++ concepts, including object-oriented programming, inheritance, and polymorphism.

## Features

- **Select a Shape**: Users can choose from Rectangle, Triangle, Circle, and Square.
- **Calculate Area and Perimeter**: Users can input the required dimensions, and the program will compute and display the area and perimeter of the selected shape.
- **Interactive User Interface**: Provides a simple and interactive console interface for user inputs and outputs.
- **Exit the Program**: Users can exit the application at any time.

## How to Run

**Clone the Repository**:
```sh
git clone https://github.com/NickDee909/ShapeHierarchy.git
cd ShapeHierarchy

Compile the Program:

sh

g++ -o ShapeHierarchy ShapeHierarchy.cpp -lm

Run the Program:

    On Windows:

    sh

ShapeHierarchy.exe

On Linux/Mac:

sh

    ./ShapeHierarchy

Usage Example

plaintext

Select a shape to calculate area and perimeter:
1. Rectangle
2. Triangle
3. Circle
4. Square
Enter your choice (1-4): 1
Enter width and height of the rectangle: 5 10
Shape: Rectangle
Area: 50
Perimeter: 30

Improvements

This program includes several improvements to enhance functionality and user experience:

    Input Validation:
        Ensures users input valid data types and positive numbers for dimensions.
        Prevents the program from crashing due to invalid inputs.

    Encapsulation:
        Repetitive code is encapsulated into separate functions (createAccount, depositToAccount, withdrawFromAccount, displayAccountBalance) for better readability and maintainability.

    Consistent Naming Conventions and Formatting:
        Applied consistent formatting and naming conventions throughout the code to improve readability.

    Detailed User Prompts and Messages:
        Clear and detailed messages guide the user through each operation, enhancing the user experience.

Additional Information

    Language: C++
    Development Environment: Visual Studio Code, GCC compiler
    Author: Nicholas Diaz
    Course: CMPS 368 - Object-Oriented Programming, Spring 2024
    Assignment: Shapes in C++
    GitHub: NickDee909

Feel free to contribute to this project by submitting pull requests or opening issues for any bugs or feature requests.