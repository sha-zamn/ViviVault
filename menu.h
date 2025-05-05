#ifndef MENU_H
#define MENU_H

#include "luck_trial.h"
#include "logic_trial.h"
#include "navigation_trial.h"

using namespace std;

bool validateInput(int&);

class TrialManager { //Manages trial progress
private:
    LuckTrial* luck; //pointer to trial of luck
    LogicTrial* logic; //pointer to trial of logic
    NavigationTrial* navigation; //pointer to trial of navigation

    bool allDone(); //Checks if all trials are done

public:
    TrialManager(string name); //Constructor
    ~TrialManager(); //Destructor to clean memory
    void showMenu(); //For trial selection
};

#endif // MENU_H
