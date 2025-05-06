#include "game.h" //Include Game class
#include "menu.h" //Include menu (TrialManager)
#include "combat.h" //Include combat (BattleSystem)
#include <iostream>
#include <cstdlib> //For rand and srand

using namespace std;

//Introduction
void Game::introduction() {
    bool validName = false; 

    cout << "<You wake up and find yourself in a mysterious room. There's a door, but it seems to be locked.>\n";
    cout << "???: How strange, I don't get visitors here. Hey there!\n";
    cout << "Vivi: I'm Vivi the Cat. But you can just call me Vivi. What's your name?\n";
    cin >> ws;
    while (!validName) {  // Loop until input is valid
        getline(cin, playerName);  // Read player name
        validName = true;  // If input is valid, set flag to true and exit the loop
    }
}
//After passing all trials
void Game::trialPassed() {
    cout << "Vivi: And that's all three!\n";
    cout << "<The door opened. But wait...>\n";
}
//Main game loop
void Game::run() {
    int choice;
    cout << "<Debug Mode On?>\n"; //For testing
    cout << "1. Yes\n2. No\n";

    while (true) { //validate input as integer
        if (validateInput(choice) && (choice == 1 || choice == 2)) break;
        cout << "<Enter 1 or 2>\n";
    }

    debugMode = (choice == 1); //Debug on for testing

    introduction(); //Calls introduction

    // First Dialogue Choices
    int dialogueChoice;

    cout << "Vivi: Nice to meet you, " << playerName << ". You look lost. How did you come here?\n";
    cout << "\n<Press 1 or 2>\n";
    cout << "1. I don't know. Did you kidnap me?\n";
    cout << "2. A bipedal cat is talking to me...\n";
    validateInput(dialogueChoice);
    if (dialogueChoice == 1) {
        cout << "\nVivi: Oh, quite the opposite! I've been waiting forever for someone to show up.\n";
    } else if (dialogueChoice == 2) {
        cout << "\nVivi: That's irrelevant! I've been here for so long. It's nice to have company.\n";
    } else {
        cout << "\nVivi: Anyway, if you want to find your way out, I can help you.\n";
    }

    // Second Dialogue Choices
    cout << "\n<Press 1 or 2>\n";
    cout << "1. Do you know how to open the door?\n";
    cout << "2. How do you know this place so well?\n";
    validateInput(dialogueChoice);
    if (dialogueChoice == 1) {
        cout << "\nVivi: Yes, you have to complete three trials to open the door!\n";
    } else if (dialogueChoice == 2) {
        cout << "\nVivi: I'm not sure myself. I just know that there are three trials you need to pass in order to open the door.\n";
    } else {
        cout << "\nVivi: If you complete three trials, the door will open.\n";
    }
//Start Trails
    TrialManager manager(playerName); //Create Trial Manager to keep track of progress
    manager.showMenu(); //Trial selection menu
    trialPassed(); //Call trial passed

//Start Combat
    BattleSystem battle;
    battle.start(debugMode); //Start combat with debug on
}
