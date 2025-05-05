#include <iostream>
#include "combat.h"
#include <cstdlib> //for rand

using namespace std;

bool validateInput(int& input);

// Constructor to initialize HP
ViviCharacter::ViviCharacter(int startHP) : hp(startHP) {}

//Check if Vivi is still alive
bool ViviCharacter::isAlive() const {
    return hp > 0;
}
//Return current HP
int ViviCharacter::getHP() const {
    return hp;
}
//Get state based on HP
string ViviCharacter::getState() const {
    if (hp >= 8) return "Agitated";
    else if (hp >= 4) return "Skeptical";
    else return "Calm";
}
//Constructor for initial HP
BattleSystem::BattleSystem() : playerHP(10), vivi(10) {}

//Get Player action: 1=Approach, 2=StandBy, 3=Reason
PlayerAction BattleSystem::getPlayerChoice() {
    int choice;
    cout << "\n<Choose your action:>\n";
    cout << "1. Approach\n2. Stand By\n3. Reason\n";

    while (true) {
        if (validateInput(choice) && choice >= 1 && choice <= 3) break;
        cout << "<Pick 1, 2, or 3>\n";
    }
    cout << endl;
    return static_cast<PlayerAction>(choice - 1); //convert int to enum
}

//Determines damage dealt based on Vivi's state and Player action
void BattleSystem::calculatePlayerDamage(ViviCharacter& vivi, PlayerAction choice) {
    string state = vivi.getState();
    int damageDealt = 0;
    
    //Approach Action
    if (choice == APPROACH && state == "Agitated") {
        cout << "\"Vivi\": STAY BACK!\n";
        damageDealt = 0;
    }
    else if (choice == APPROACH && state == "Skeptical") {
        cout << "\"Vivi\": Not another step!\n";
        damageDealt = 1;
        vivi.hp -= 1;
    }
    else if (choice == APPROACH && state == "Calm") {
        cout << "\"Vivi\": ...I don't want to hurt you...\n";
        damageDealt = 1;
        vivi.hp -= 1;
    }
    //Stand By Action
    else if (choice == STANDBY) {
        cout << "\"Vivi\": Scared?\n";
        damageDealt = 1;
        vivi.hp -= 1;
    }
    //Reason Action
    else if (choice == REASON && state == "Agitated") {
        cout << "\"Vivi\": How dare you talk back!\n";
        damageDealt = 0;
    }
    else if (choice == REASON && state == "Skeptical") {
        cout << "\"Vivi\": That doesn't make any sense...\n";
        damageDealt = 1;
        vivi.hp -= 1;
    }
    else if (choice == REASON && state == "Calm") {
        cout << "\"Vivi\": I remember...\n";
        damageDealt = 2;
        vivi.hp -= 1;
    }
    cout << "You deal " << damageDealt << " damage to \"Vivi\".\n\n"; //Output damange dealt
}

//Vivi retaliates based on her state and player action
int ViviCharacter::retaliate(PlayerAction action) {
    int r = rand() % 100; //Generate random roll (to determine percentage)
    lastRoll = r; //Store roll of last turn (for debug test)
    int damage = 0;

    if (hp <= 0) return 0; //Vivi defeated
    //Agitated
    if (hp == 10) {
        damage = 2;
    }
    else if (hp >= 8) {
        if (action == APPROACH) {
            damage = (r < 80) ? 2 : 1;
        }
        else if (action == STANDBY) {
            damage = (r < 60) ? 2 : ((r < 90) ? 1 : 0);
        }
        else if (action == REASON) {
            damage = (r < 40) ? 2 : ((r < 90) ? 1 : 0);
        }
    }
    //Skeptical
    else if (hp >= 4) {
        if (action == APPROACH) {
            damage = (r < 50) ? 2 : 1;
        }
        else if (action == STANDBY) {
            damage = (r < 30) ? 2 : ((r < 80) ? 1 : 0);
        }
        else if (action == REASON) {
            damage = (r < 10) ? 2 : ((r < 80) ? 1 : 0);
        }
    }
    //Calm
    else {
        if (action == APPROACH) {
            damage = (r < 30) ? 2 : ((r < 70) ? 1 : 0);
        }
        else if (action == STANDBY) {
            damage = (r < 10) ? 2 : ((r < 60) ? 1 : 0);
        }
        else if (action == REASON) {
            damage = (r < 30) ? 1 : 0;
        }
    }

    return damage; //Return Vivi's retaliation damage
}

//Get the last roll (for debug mode)
int ViviCharacter::getLastRoll() const {
    return lastRoll;
}

//Start the battle
void BattleSystem::start(bool debugMode) {
    cout << "\n<A fog suddenly surrounds you and Vivi.>\n";
    cout << "Vivi: What is this...?\n\n";
    cout << "<Vivi stiffens. Her eyes glow red.>\n";
    cout << "<\"Vivi\" turns to face you — now hostile and disoriented.>\n\n";

    int choiceBeforeBattle;
    cout << "1. Vivi, snap out of it!\n";
    cout << "2. What's happening?!\n";
    validateInput(choiceBeforeBattle); // Default behavior keeps first valid choice
    if (choiceBeforeBattle == 1) {
        cout << "\n\"Vivi\": I can't...\n\n";
    } else if (choiceBeforeBattle == 2) {
        cout << "\n\"Vivi\": I feel...a surging power in me.\n\n";
    } else {
        cout << "\n\"Vivi\": No one gets to leave this place!\n\n";
    }

//Player choices
    cout << "<Your Options:>\n";
    cout << "1. Approach — Try to sneak towards Vivi\n";
    cout << "2. Stand By — Stay still, let her act first\n";
    cout << "3. Reason — Try to talk her down\n\n";

//Main combat loop
    while (vivi.isAlive() && playerHP > 0) {
        cout << "--- NEW TURN ---\n";
        cout << "Your HP: " << playerHP << " | \"Vivi\" HP: " << vivi.getHP() << "\n";
        string state = vivi.getState();
//Show Vivi's state
        if (state == "Agitated") {
            cout << R"(
       ∧  _ ∧ 
    ฅ(=´ò ﻌ ó=)ฅ
        )" << endl;
        } else if (state == "Skeptical") {
            cout << R"(
      ∧_   _∧ 
     (=´° ^°=)?
        )" << endl;
        } else if (state == "Calm") {
            cout << R"(
       ∧    ∧ 
     (= - ω -=)
        )" << endl;
        }

//Player inputs choice
        PlayerAction choice = getPlayerChoice();
    
//Calculate damage dealt & update Vivi's HP
        calculatePlayerDamage(vivi, choice);

//Check if Vivi's HP is down to 0
        if (!vivi.isAlive()) continue;

//Vivi retaliates
        int retaliation = vivi.retaliate(choice);
        playerHP -= retaliation;

        cout << "\"Vivi\" retaliates! She deals " << retaliation << " damage to you.\n\n";

        showDebugTurnInfo(vivi, choice, debugMode); //If debug on, shows turn details
    }

//Result after either party HP reaches 0
    if (playerHP <= 0) {
        cout << "\n<You collapse. The fog consumes you.>\n";
    } else {
        cout << "\n<Vivi comes back to her senses.>\n";
        cout << "\nVivi: I'm back to myself... Thank you for saving me!\n"
             << "<The fog dissappears. Both of you walk free.>\n\n";
    }

    cout << "\n--- BATTLE ENDS ---\n\n";
}
