//Include necessary headers for game modules and implementation files
#include "game.h" //Game class
#include "trial.h" //Trial base class
#include "menu.h"
#include "luck_trial.h"
#include "logic_trial.h"
#include "navigation_trial.h"
#include "combat.h"
#include "game.cpp"
#include "trial.cpp"
#include "luck_trial.cpp"
#include "logic_trial.cpp"
#include "navigation_trial.cpp"
#include "combat.cpp"
#include "debug.cpp" //Debug test

int main() {
    Game game; //Create Game object
    game.run(); //Call run() to start game
    return 0;
}

//Bash command:
//g++ main.cpp game.cpp trial.cpp luck_trial.cpp logic_trial.cpp navigation_trial.cpp combat.cpp debug.cpp -o vivivault