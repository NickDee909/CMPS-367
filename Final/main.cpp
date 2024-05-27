#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>   
#include <limits>  
using namespace std;

// Function to perform recursive bubble sort
void bubbleSort(int arr[], int n) {
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort. After this pass, the largest element is moved (or bubbled) to end.
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // Largest element is fixed, recur for remaining array
    bubbleSort(arr, n - 1);
}

// Function to calculate average score
double calculateAverage(int arr[], int n, int pointsPossible) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return (static_cast<double>(total) / (n * pointsPossible)) * 100;
}

// Function to find the minimum score
int findMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum score
int findMaximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to display available departments
void displayDepartments() {
    cout << "Available departments:" << endl;
    cout << "1. CMPS (Computer Science)" << endl;
    cout << "2. MATH (Mathematics)" << endl;
    cout << "3. PHYS (Physics)" << endl;
    cout << "4. CHEM (Chemistry)" << endl;
    cout << "5. BIOL (Biology)" << endl;
    cout << "6. ENGL (English)" << endl;
    cout << "7. HIST (History)" << endl;
    cout << "8. ECON (Economics)" << endl;
    cout << "Please enter the department abbreviation as input (e.g., CMPS):" << endl;
}

// Template function to validate input
template <typename T>
void validateInput(T& input) {
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter a valid value: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    // Prompt user for course and assignment details
    string courseDept, courseName, assignmentName;
    int courseNum, pointsPossible, numStudents;

    cout << "Welcome to Grade Calculator!" << endl;
    cout << "Do you want to see available departments? (y/n): ";
    char seeDepts;
    cin >> seeDepts;
    if (seeDepts == 'y' || seeDepts == 'Y') {
        displayDepartments();
    }

    cout << "Enter the course dept: ";
    cin >> courseDept;
    cout << "Enter the course number: ";
    validateInput(courseNum);
    cout << "Enter the course name: ";
    cin.ignore();
    getline(cin, courseName);
    cout << "Enter the name of the assignment: ";
    getline(cin, assignmentName);
    cout << "Enter points possible: ";
    validateInput(pointsPossible);
    while (pointsPossible <= 0) {
        cout << "Points possible must be greater than 0. Enter points possible: ";
        validateInput(pointsPossible);
    }
    cout << "Enter the number of students that will be scored: ";
    validateInput(numStudents);
    while (numStudents <= 0) {
        cout << "Number of students must be greater than 0. Enter the number of students: ";
        validateInput(numStudents);
    }

    // Create a dynamic array for student scores
    int* scores = new int[numStudents];

    // Input scores for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the score for student " << (i + 1) << ": ";
        validateInput(scores[i]);
        while (scores[i] < 0 || scores[i] > pointsPossible) {
            cout << "Invalid score. Enter a score between 0 and " << pointsPossible << ": ";
            validateInput(scores[i]);
        }
    }

    // Sort the scores using recursive bubble sort
    bubbleSort(scores, numStudents);

    // Calculate average, minimum, and maximum scores
    double averageScore = calculateAverage(scores, numStudents, pointsPossible);
    int minScore = findMinimum(scores, numStudents);
    int maxScore = findMaximum(scores, numStudents);

    // Output the results
    cout << "\nCourse: " << courseDept << " " << courseNum << ": " << courseName << endl;
    cout << "Scores: ";
    for (int i = 0; i < numStudents; i++) {
        cout << scores[i] << " ";
    }
    cout << "\nAverage: " << fixed << setprecision(2) << averageScore << "%" << endl;
    cout << "Lowest Score: " << minScore << endl;
    cout << "Highest Score: " << maxScore << endl;

    // Clean up dynamic memory
    delete[] scores;

    cout << "Thank you for using the grade calculator!" << endl;

    return 0;
}
