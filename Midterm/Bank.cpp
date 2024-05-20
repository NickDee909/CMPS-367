/*
 * Author: Nicholas Diaz
 * Course: CMPS 368 - Object-Oriented Programming, Spring 2024
 * Assignment: Bank App in C++ (Midterm)
 * GitHub: https://github.com/NickDee909
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// BankAccount class to manage individual accounts
class BankAccount {
public:
    string name;
    int accountNumber;
    double balance;

    // Constructor to initialize account with name and balance
    BankAccount(string n, double b) {
        name = n;
        balance = b;
        accountNumber = generateAccountNumber();
    }

    // Method to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Method to withdraw money, returns true if successful
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Method to display current balance
    void displayBalance() const {
        cout << "Your current balance is $" << balance << endl;
    }

private:
    // Static method to generate a unique account number
    static int generateAccountNumber() {
        static bool first = true;
        if (first) {
            srand(time(nullptr));  // Seed the random number generator
            first = false;
        }
        return rand() % 10000 + 10000;  // Generate a 5-digit account number
    }
};

vector<BankAccount> accounts;  // Vector to store bank accounts

// Function to create a new account
void createAccount() {
    string name;
    double initialBalance;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your initial balance: ";
    cin >> initialBalance;

    BankAccount newAccount(name, initialBalance);
    accounts.push_back(newAccount);

    cout << "Congratulations " << name << "! You have successfully opened your new bank account with an initial balance of $" << initialBalance << ". Your account number is " << newAccount.accountNumber << "." << endl;
}

// Function to find an account by account number
BankAccount* findAccount(int accountNumber) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

// Function to deposit money into an account
void depositMoney() {
    int accountNumber;
    double depositAmount;
    cout << "Enter the account number: ";
    cin >> accountNumber;

    BankAccount* account = findAccount(accountNumber);
    if (account) {
        cout << "Enter the amount that you would like to deposit: ";
        cin >> depositAmount;
        account->deposit(depositAmount);
        cout << "Congratulations " << account->name << "! You have successfully deposited the amount of $" << depositAmount << " in your account #" << account->accountNumber << ". Your current balance is $" << account->balance << "." << endl;
    }
    else {
        cout << "No account number exists!" << endl;
    }
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accountNumber;
    double withdrawAmount;
    cout << "Enter the account number: ";
    cin >> accountNumber;

    BankAccount* account = findAccount(accountNumber);
    if (account) {
        cout << "Enter the amount that you would like to withdraw: ";
        cin >> withdrawAmount;
        if (account->withdraw(withdrawAmount)) {
            cout << "Congratulations " << account->name << "! You have successfully withdrawn the amount of $" << withdrawAmount << " from your account #" << account->accountNumber << ". Your current balance is $" << account->balance << "." << endl;
        }
        else {
            cout << "Insufficient funds!" << endl;
        }
    }
    else {
        cout << "No account number exists!" << endl;
    }
}

// Function to display the balance of an account
void displayBalance() {
    int accountNumber;
    cout << "Enter the account number: ";
    cin >> accountNumber;

    BankAccount* account = findAccount(accountNumber);
    if (account) {
        account->displayBalance();
    }
    else {
        cout << "No account number exists!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "***************Welcome to Chase***************" << endl;
        cout << "Please choose one of the following operations" << endl;
        cout << "1- Create a new bank account with an initial balance" << endl;
        cout << "2- Deposit Money to an Account" << endl;
        cout << "3- Withdraw Money from an Account" << endl;
        cout << "4- Display Current Balance of an Account" << endl;
        cout << "5- Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            displayBalance();
            break;
        case 5:
            cout << "Thank you for using the bank account management system!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }

        if (choice != 5) {
            cout << "Press any key to return to Main Menu!" << endl;
            cin.ignore();
            cin.get();
        }

    } while (choice != 5);

    return 0;
}

