#ifndef GAME_H
#define GAME_H

#include <string>
#include "menu.h"
#include "combat.h"

using namespace std;

bool validateInput(int&); //validate input as integer

//Define Game class
class Game {
private:
    string playerName;
    bool debugMode = false; //For debug mode
    void introduction();
    void trialPassed();

public:
    void run(); //Run game
};

#endif // GAME_H
