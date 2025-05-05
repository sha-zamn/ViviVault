#include "luck_trial.h"
#include <iostream>
#include <cstdlib> //for rand, srand

using namespace std;

// Constructor
LuckTrial::LuckTrial(string name) : Trial(name) {
    srand(7); //fixed seed
    luckyNumber = rand() % 10 + 1;
}

// Run function
void LuckTrial::run() {
    if (completed) {
        cout << "\nVivi: You've already completed the Trial of Luck.\n";
        return;
    }

    int guess;
    cout << "\nVivi: The Trial of Luck, huh? Let's see how lucky you really are.\n";
    cout << "Vivi: Guess a number from 1 to 10: ";

    while (true) { //loop until correct guess
        if (!validateInput(guess)) continue;
        if (guess == luckyNumber) {
            cout << "Vivi: Lucky guess!\n";
            completed = true;
            return;
        }
        cout << "Vivi: Ah, how unfortunate. Let's try again.\n";
    }
}

// Check completion
bool LuckTrial::isCompleted() const {
    return completed;
}