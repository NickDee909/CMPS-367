/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Bank Management in C++
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> 

class BankAccount {
private:
    std::string name;
    int accountNumber;
    double balance;

public:
    // Constructor to create a new account
    BankAccount(std::string userName, double initialBalance) {
        name = userName;
        balance = initialBalance;
        accountNumber = rand() % 10000;  // Random account number between 0 and 9999
        std::cout << "Congratulations " << name << "! You have successfully opened your new bank account with an initial balance of $" << balance << ". Your account number is " << accountNumber << ".\n";
    }

    // Getter for account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Deposit money into the account
    void deposit(double amount) {
        balance += amount;
        std::cout << "Congratulations " << name << "! You have successfully deposited the amount of $" << amount << " in your account #" << accountNumber << ". Your current balance is $" << balance << ".\n";
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds for withdrawal.\n";
            return;
        }
        balance -= amount;
        std::cout << "Congratulations " << name << "! You have successfully withdrawn the amount of $" << amount << " from your account #" << accountNumber << ". Your current balance is $" << balance << ".\n";
    }

    // Display the current balance
    void displayBalance() const {
        std::cout << "Your current balance is $" << balance << ".\n";
    }
};

void createAccount(std::vector<BankAccount>& accounts) {
    std::string name;
    double initialBalance;
    
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your initial balance: ";
    while (!(std::cin >> initialBalance) || initialBalance < 0) {
        std::cout << "Invalid input. Please enter a positive number for the initial balance: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    accounts.push_back(BankAccount(name, initialBalance));
}

void depositToAccount(std::vector<BankAccount>& accounts) {
    int accountNumber;
    double amount;

    std::cout << "Enter the account number: ";
    std::cin >> accountNumber;
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            std::cout << "Enter the amount that you would like to deposit: ";
            while (!(std::cin >> amount) || amount < 0) {
                std::cout << "Invalid input. Please enter a positive number for the deposit amount: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            account.deposit(amount);
            return;
        }
    }
    std::cout << "No account number exists!\n";
}

void withdrawFromAccount(std::vector<BankAccount>& accounts) {
    int accountNumber;
    double amount;

    std::cout << "Enter the account number: ";
    std::cin >> accountNumber;
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            std::cout << "Enter the amount that you would like to withdraw: ";
            while (!(std::cin >> amount) || amount < 0) {
                std::cout << "Invalid input. Please enter a positive number for the withdrawal amount: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            account.withdraw(amount);
            return;
        }
    }
    std::cout << "No account number exists!\n";
}

void displayAccountBalance(const std::vector<BankAccount>& accounts) {
    int accountNumber;

    std::cout << "Enter the account number: ";
    std::cin >> accountNumber;
    for (const auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            account.displayBalance();
            return;
        }
    }
    std::cout << "No account number exists!\n";
}

int main() {
    std::vector<BankAccount> accounts;
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int choice;

    while (true) {
        std::cout << "***************Welcome to Chase***************\n";
        std::cout << "Please choose one of the following operations:\n";
        std::cout << "1- Create a new bank account with an initial balance\n";
        std::cout << "2- Deposit Money to an Account\n";
        std::cout << "3- Withdraw Money from an Account\n";
        std::cout << "4- Display Current Balance of an Account\n";
        std::cout << "5- Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            createAccount(accounts);
            break;
        case 2:
            depositToAccount(accounts);
            break;
        case 3:
            withdrawFromAccount(accounts);
            break;
        case 4:
            displayAccountBalance(accounts);
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        std::cout << "Press any key to return to Main Menu!\n";
        std::cin.get();
    }
    return 0;
}
