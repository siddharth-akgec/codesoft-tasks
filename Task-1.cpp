#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));
    
    int number = rand() % 100 + 1;  // Random number between 1 and 100
    int guess;
    
    cout << "=== Number Guessing Game ===" << endl;
    cout << "Guess a number between 1 and 100." << endl;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        
        if (guess > number) {
            cout << "Too high! Try again." << endl;
        } 
        else if (guess < number) {
            cout << "Too low! Try again." << endl;
        } 
        else {
            cout << "Congratulations! You guessed the correct number: " << number << endl;
        }
    } while (guess != number);
   return 0;
}