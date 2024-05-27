
# Bank Management System

## Overview
The Bank Management System is a simple console-based application that allows users to manage bank accounts. The system supports creating new accounts, depositing money, withdrawing money, and displaying the current balance of an account. This program is designed for educational purposes to demonstrate basic C++ concepts, including object-oriented programming, input validation, and user interaction.

## Features
- **Create a New Account**: Users can create a new bank account by providing their name and an initial balance. Each account is assigned a unique random account number.
- **Deposit Money**: Users can deposit money into an existing account by entering the account number and the deposit amount.
- **Withdraw Money**: Users can withdraw money from an existing account by entering the account number and the withdrawal amount. The system checks for sufficient funds before processing the withdrawal.
- **Display Account Balance**: Users can check the current balance of an existing account by entering the account number.
- **Exit the Program**: Users can exit the application at any time.

## How to Run
1. **Clone the Repository**:
    ```sh
    git clone https://github.com/yourusername/yourrepository.git
    cd yourrepository
    ```

2. **Compile the Program**:
    ```sh
    g++ -o BankManagement BankManagement.cpp
    ```

3. **Run the Program**:
    - On Windows:
        ```sh
        BankManagement.exe
        ```
    - On Linux/Mac:
        ```sh
        ./BankManagement
        ```

## Usage Example
```plaintext
***************Welcome to Chase***************
Please choose one of the following operations:
1- Create a new bank account with an initial balance
2- Deposit Money to an Account
3- Withdraw Money from an Account
4- Display Current Balance of an Account
5- Exit

Improvements

This program includes several improvements to enhance functionality and user experience:

    Input Validation:
        Ensures that users input valid data types and positive numbers for balances and amounts.
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

Feel free to contribute to this project by submitting pull requests or opening issues for any bugs or feature requests.