#include <iostream>
using namespace std;
#include "combat.h" //Include classes from combat

//Helper function to define player choice
string actionOption(PlayerAction action) {
    switch (action) {
        case APPROACH: return "Approach";
        case STANDBY: return "Stand By";
        case REASON: return "Reason";
        default: return "No action";
    }
}

//Function to show turn details
void showDebugTurnInfo(ViviCharacter& vivi, PlayerAction choice, bool debugMode) {
    if (!debugMode) return; //Exit if debug off
    
    int r = vivi.getLastRoll(); //Get roll from last turn
    string state = vivi.getState(); //Get Vivi's state

//Print last turn details
    cout << "--- TURN INFO ---\n";
    cout << "Player action: " << actionOption(choice) << "\n";
    cout << "Vivi's State: " << state << "\n";
    cout << "Roll: " << r << "%\n";

    //Agitated
    if (state == "Agitated") {
        cout << "Retaliation Logic (Agitated):\n";
        if (choice == APPROACH) {
            cout << "  0-79%: 2 damage\n";
            cout << "  80-99%: 1 damage\n";
            cout << "  Result: " << r << "% → " << (r < 80 ? "2 dmg" : "1 dmg") << "\n";
        }
        else if (choice == STANDBY) {
            cout << "  0-59%: 2 damage\n";
            cout << "  60-89%: 1 damage\n";
            cout << "  90-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 60 ? "2 dmg" : (r < 90 ? "1 dmg" : "0 dmg")) << "\n";
        }
        else if (choice == REASON) {
            cout << "  0-39%: 2 damage\n";
            cout << "  40-89%: 1 damage\n";
            cout << "  90-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 40 ? "2 dmg" : (r < 90 ? "1 dmg" : "0 dmg")) << "\n";
        }
    }
    //Skeptical
    else if (state == "Skeptical") {
        cout << "Retaliation Logic (Skeptical):\n";
        if (choice == APPROACH) {
            cout << "  0-49%: 2 damage\n";
            cout << "  50-99%: 1 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 50 ? "2 dmg" : "1 dmg") << "\n";
        }
        else if (choice == STANDBY) {
            cout << "  0-29%: 2 damage\n";
            cout << "  30-79%: 1 damage\n";
            cout << "  80-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 30 ? "2 dmg" : (r < 80 ? "1 dmg" : "0 dmg")) << "\n";
        }
        else if (choice == REASON) {
            cout << "  0-9%: 2 damage\n";
            cout << "  10-79%: 1 damage\n";
            cout << "  80-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 10 ? "2 dmg" : (r < 80 ? "1 dmg" : "0 dmg")) << "\n";
        }
    }
    //Calm
    else if (state == "Calm") {
        cout << "Retaliation Logic (Calm):\n";
        if (choice == APPROACH) {
            cout << "  0-29%: 2 damage\n";
            cout << "  30-69%: 1 damage\n";
            cout << "  70-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 30 ? "2 dmg" : (r < 70 ? "1 dmg" : "0 dmg")) << "\n";
        }
        else if (choice == STANDBY) {
            cout << "  0-9%: 2 damage\n";
            cout << "  10-59%: 1 damage\n";
            cout << "  60-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 10 ? "2 dmg" : (r < 60 ? "1 dmg" : "0 dmg")) << "\n";
        }
        else if (choice == REASON) {
            cout << "  0-29%: 1 damage\n";
            cout << "  30-99%: 0 damage\n";
            cout << "  Result: " << r << "% → " 
                 << (r < 30 ? "1 dmg" : "0 dmg") << "\n";
        }
    }

    cout << "--- TURN OVER ---\n\n";
}
