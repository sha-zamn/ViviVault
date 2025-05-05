#include <iostream>
#include "trial.h" //Include Trial class
#include "menu.h"
#include "luck_trial.h"
#include "logic_trial.h"
#include "navigation_trial.h"
#include <cstdlib> //For rand and srand
using namespace std;

// Input validation function (used by all trials)
bool validateInput(int& input) {
    while (!(cin >> input)) {
        cout << "<Try entering a number again.>\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    return true;
}
// Base Trial constructor
Trial::Trial(string name) {
    playerName = name; //Set player name in Trials
}
//TrialManager Constructor
TrialManager::TrialManager(string name) {
    luck = new LuckTrial(name); //Create trial of luck
    logic = new LogicTrial(name); //Create trial of logic
    navigation = new NavigationTrial(name); //Create trial of navigation
}
//TrialManager destructor to clean dynamically allocated memory
TrialManager::~TrialManager() {
    delete luck;
    delete logic;
    delete navigation;
}
//Checks if trials are done
bool TrialManager::allDone() {
    return luck->isCompleted() && logic->isCompleted() && navigation->isCompleted();
}
//Trial selection menu
void TrialManager::showMenu() {
    cout << "Vivi: Alright, let's start the trials?\n";
    cout << "Vivi: You can choose which trial to do first.\n";

    while (!allDone()) {
        int choice = 0;

        cout << "\nVivi: Which trial would you like to try now?\n";
        cout << "1. Trial of Luck\n";
        cout << "2. Trial of Logic\n";
        cout << "3. Trial of Navigation\n";

        while (true) {
            if (validateInput(choice) && choice >= 1 && choice <= 3) break;
            cout << "Vivi: Hmm? Didn't catch that.\n";
        }

        switch (choice) {
            case 1: luck->run(); break; //Start trial of luck
            case 2: logic->run(); break; //Start trial of logic
            case 3: navigation->run(); break; //Start trial of navigationgit add .
        }
    }
}
