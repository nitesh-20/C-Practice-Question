#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Number Guessing Game
int main() {
    // Seed random number generator
    srand(time(0));
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 100.\n";
    cout << "Can you guess it?\n\n";
    
    int secretNumber = rand() % 100 + 1;  // Random number 1-100
    int guess;
    int attempts = 0;
    int maxAttempts = 7;
    
    while (attempts < maxAttempts) {
        cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << "\n";
        cout << "Enter your guess: ";
        
        if (!(cin >> guess)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        attempts++;
        
        if (guess == secretNumber) {
            cout << "\nCongratulations! You guessed it!\n";
            cout << "The number was " << secretNumber << "\n";
            cout << "You won in " << attempts << " attempts!\n";
            return 0;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try a higher number.\n";
        }
        else {
            cout << "Too high! Try a lower number.\n";
        }
        
        // Give additional hints
        int difference = abs(guess - secretNumber);
        if (difference <= 5) {
            cout << "You're very close!\n";
        }
        else if (difference <= 15) {
            cout << "You're getting warmer!\n";
        }
        
        cout << "\n";
    }
    
    cout << "Game over! You've used all " << maxAttempts << " attempts.\n";
    cout << "The number was " << secretNumber << "\n";
    cout << "Better luck next time!\n";
    
    return 0;
}