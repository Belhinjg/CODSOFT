#include <iostream>

using namespace std;

// Function prototypes
void addition(float num1, float num2);
void subtraction(float num1, float num2);
void multiplication(float num1, float num2);
void division(float num1, float num2);

int main() {
    float num1, num2;
    int choice;

    // Input first number
    cout << "Enter first number: ";
    cin >> num1;

    // Input second number
    cout << "Enter second number: ";
    cin >> num2;

    // Display menu and get choice
    cout << "\nSelect operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Perform operation based on user's choice
    switch (choice) {
        case 1:
            addition(num1, num2);
            break;
        case 2:
            subtraction(num1, num2);
            break;
        case 3:
            multiplication(num1, num2);
            break;
        case 4:
            if (num2 == 0) {
                cout << "Error! Division by zero is not allowed." << endl;
            } else {
                division(num1, num2);
            }
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
    }

    return 0;
}

// Function definitions

void addition(float num1, float num2) {
    cout << "Result of addition: " << num1 + num2 << endl;
}

void subtraction(float num1, float num2) {
    cout << "Result of subtraction: " << num1 - num2 << endl;
}

void multiplication(float num1, float num2) {
    cout << "Result of multiplication: " << num1 * num2 << endl;
}

void division(float num1, float num2) {
    cout << "Result of division: " << num1 / num2 << endl;
}
