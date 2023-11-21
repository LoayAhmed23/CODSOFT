#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    do {
        cout << "Please guess the number: ";
        cin >> guess;

        if (guess - secretNumber <= 5 && guess - secretNumber > 0) {
            cout << "Getting close! Try lower." << endl;
        }
        else if (guess - secretNumber >= -5 && guess - secretNumber < 0) {
            cout << "Getting close! Try higher." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ")" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
