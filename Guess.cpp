#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // Seed for random number generation

    int secretNumber = rand() % 100 + 1;  // Generate secret number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have chosen a number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high!\n";
        } else if (guess < secretNumber) {
            cout << "Too low!\n";
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts!\n";
        }
    } while (guess != secretNumber);

    return 0;
}
