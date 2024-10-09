#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator with current time
    int playerChoice;  // Variable to store player's choice
    int computerChoice;  // Variable to store computer's randomly generated choice

    // Prompt the player to enter a choice
    cout << "Enter your choice:\n";
    cout << "1 for Rock\n";
    cout << "2 for Paper\n";
    cout << "3 for Scissors\n";
    cin >> playerChoice;  // Get player's choice

    // Generate computer's choice
    computerChoice = (rand() % 3) + 1;  // Random number between 1 and 3

    // Determine the winner
    if (playerChoice == computerChoice) {
        cout << "It's a tie!\n";
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
}
