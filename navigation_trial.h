#ifndef NAVIGATION_TRIAL_H
#define NAVIGATION_TRIAL_H

#include "trial.h" //include base trial class
#include <vector> //for vector
#include <string>

bool validateInput(int&);
using namespace std;

class NavigationTrial : public Trial {
private:
    const int ROWS = 9;
    const int COLS = 9;

    std::vector<vector<char>> maze = { //9x9 maze (o=path, #=wall)
        {'#', 'o', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'o', '#', '#', 'o', 'o', '#', 'o', '#'},
        {'#', 'o', 'o', '#', '#', 'o', '#', 'o', '#'},
        {'#', 'o', '#', 'o', 'o', 'o', '#', 'o', '#'},
        {'#', 'o', '#', 'o', '#', 'o', 'o', 'o', '#'},
        {'#', 'o', 'o', 'o', '#', 'o', '#', '#', '#'},
        {'#', 'o', '#', 'o', '#', 'o', '#', '#', '#'},
        {'#', '#', 'o', 'o', '#', 'o', 'o', 'o', '#'},
        {'#', '#', '#', '#', '#', '#', '#', 'o', '#'}
    };
//Initialize player coordinates
    int playerX = 0;
    int playerY = 1;

    void createMaze(); //Prints laze
    bool correctMove(int x, int y); //validate move
    void movePlayer(char move); //update palyer coordinates

public:
    bool completed = false; //Flag to check completion status
    NavigationTrial(string name); // Constructor
    void run(); //runs trial
    bool isCompleted() const;
};

#endif // NAVIGATION_TRIAL_H