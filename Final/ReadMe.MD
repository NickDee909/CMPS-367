# Grade Calculator

## Overview

The Grade Calculator is a console-based application that allows users to manage and calculate student grades for a course assignment. The system supports entering course details, recording student scores, sorting scores, and calculating statistical information such as average, minimum, and maximum scores. This program is designed for educational purposes to demonstrate basic C++ concepts, including object-oriented programming, recursion, input validation, and user interaction.

## Features

- **View Available Departments**: Users can view a list of available departments for reference.
- **Enter Course Details**: Users can input the course department, course number, course name, assignment name, and points possible for the assignment.
- **Record Student Scores**: Users can enter the number of students and record each student's score.
- **Sort Scores**: Scores are sorted in ascending order using a recursive bubble sort algorithm.
- **Calculate Statistics**: The program calculates and displays the average score, minimum score, and maximum score.
- **Exit the Program**: Users can exit the application at any time.

## How to Run

**Clone the Repository**:
```sh
git clone https://github.com/NickDee909/GradeCalculator.git
cd GradeCalculator

Compile the Program:

sh

g++ -o GradeCalculator GradeCalculator.cpp

Run the Program:

    On Windows:

    sh

GradeCalculator.exe

On Linux/Mac:

sh

    ./GradeCalculator

Usage Example

plaintext

Welcome to Grade Calculator!
Do you want to see available departments? (y/n): y
Available departments:
1. CMPS (Computer Science)
2. MATH (Mathematics)
3. PHYS (Physics)
4. CHEM (Chemistry)
5. BIOL (Biology)
6. ENGL (English)
7. HIST (History)
8. ECON (Economics)
Please enter the department abbreviation as input (e.g., CMPS):
Enter the course dept: CMPS
Enter the course number: 367
Enter the course name: Object Oriented Language C++
Enter the name of the assignment: Final Project
Enter points possible: 100
Enter the number of students that will be scored: 5
Enter the score for student 1: 85
Enter the score for student 2: 90
Enter the score for student 3: 75
Enter the score for student 4: 95
Enter the score for student 5: 80

Course: CMPS 367: Object Oriented Language C++
Scores: 75 80 85 90 95
Average: 85.00%
Lowest Score: 75
Highest Score: 95
Thank you for using the grade calculator!

Improvements

This program includes several improvements to enhance functionality and user experience:

    Input Validation:
        Ensures that users input valid data types and positive numbers for scores and other inputs.
        Prevents the program from crashing due to invalid inputs.

    Encapsulation:
        Repetitive code is encapsulated into separate functions (validateInput, displayDepartments, etc.) for better readability and maintainability.

    Consistent Naming Conventions and Formatting:
        Applied consistent formatting and naming conventions throughout the code to improve readability.

    Detailed User Prompts and Messages:
        Clear and detailed messages guide the user through each operation, enhancing the user experience.

Additional Information

    Language: C++
    Development Environment: Visual Studio Code, GCC compiler
    Author: Nicholas Diaz
    Course: CMPS 367 - Object-Oriented Language C++, Spring 2024
    Assignment: Final Project
    GitHub: NickDee909

Feel free to contribute to this project by submitting pull requests or opening issues for any bugs or feature requests.

