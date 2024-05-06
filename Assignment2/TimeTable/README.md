# Multiplication Table Generator

## Overview
The Multiplication Table Generator is a C++ console application created for the CMPS 368 - Object-Oriented Programming course, Spring 2024. This tool is designed to help users generate customizable multiplication tables, allowing them to specify both the range of multipliers and the range of multiplicands.

## Features
- **Customizable Ranges**: Users can specify the start and end of both the numbers they want to multiply and the numbers they want to multiply by.
- **Formatted Output**: Displays the multiplication table in a neatly formatted grid using `std::setw` for easy readability.
- **Interactive User Experience**: Prompts users to create multiple multiplication tables in one session, with easy-to-follow instructions for modifying range inputs.

## How to Run
To run the Multiplication Table Generator, follow these steps:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/NickDee909/CMPS367-OOP.git

g++ main.cpp -o MultiplicationTable

./MultiplicationTable

# usage example 

Enter the starting range for Multiplication Table: 1
Enter the ending range for Multiplication Table: 5
Enter the starting range for multiplying the numbers in Multiplication Table: 1
Enter the ending range for multiplying the numbers in Multiplication Table: 10

Here is the multiplication table for 1 to 10 in the range of 1 to 5:
    X    1    2    3    4    5    6    7    8    9   10
    1    1    2    3    4    5    6    7    8    9   10
    2    2    4    6    8   10   12   14   16   18   20
    3    3    6    9   12   15   18   21   24   27   30
    4    4    8   12   16   20   24   28   32   36   40
    5    5   10   15   20   25   30   35   40   45   50

Do you want to create another multiplication table (y/n): n
Thank you for using the multiplication table generator!

#

