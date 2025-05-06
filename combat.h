#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include <cstdlib> //For rand, srand (determine roll)
#include <iostream>

using namespace std;

bool validateInput(int& input);

//Player actions in combat
enum PlayerAction { APPROACH, STANDBY, REASON };

//Vivi Character Class
class ViviCharacter {
private:
    int lastRoll = 0; //Stores Vivi's retaliation roll from last turn

public:
    ViviCharacter(int startHP = 10); //Constructor
    int hp; //Vivi HP
    bool isAlive() const; //Checks if HP is above 0
    int getHP() const; //Gets current HP
    string getState() const; //Gets current state
    int retaliate(PlayerAction action); //Vivi's reaction
    int getLastRoll() const; //Get last roll
};

//Battle System Class
class BattleSystem {
private:
    int playerHP = 10;
    ViviCharacter vivi; //Opponent
    PlayerAction getPlayerChoice();
    void calculatePlayerDamage(ViviCharacter& vivi, PlayerAction choice);

public:
    BattleSystem(); //Constructor
    void start(bool debugMode); //Starts combat with debug mode on
};

void showDebugTurnInfo(ViviCharacter& vivi, PlayerAction choice, bool debugMode); //For testing

#endif // COMBAT_H
