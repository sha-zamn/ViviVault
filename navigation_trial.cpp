#include "navigation_trial.h"
#include <iostream>

using namespace std;

//Constructor for the trial
NavigationTrial::NavigationTrial(string name) : Trial(name) {}

//Display player position in maze
void NavigationTrial::createMaze() {
    for (int i = 0; i < ROWS; i++) { //interate each column
        for (int j = 0; j < COLS; j++) {
            if (i == playerX && j == playerY)
                cout << "V "; //player position is V
            else
                cout << maze[i][j] << " ";
        }
        cout << endl; //new row
    }
}

//validate move (inside bound & not wall)
bool NavigationTrial::correctMove(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] != '#');
}

//move player and update position
void NavigationTrial::movePlayer(char move) {
    int newX = playerX, newY = playerY;

    if (move == 'w') newX--;
    else if (move == 's') newX++;
    else if (move == 'a') newY--;
    else if (move == 'd') newY++;

    else {
        cout << "<Try again using w (up), a (left), s (down), or d (right).>\n";
        return;
    }

    if (correctMove(newX, newY)) { //validate move
        playerX = newX;
        playerY = newY;
    } else {
        cout << "Vivi: You cannot go through walls.\n";
    }
}

//Function to run trial
void NavigationTrial::run() {
    if (completed) {
        cout << "\nVivi: You've already completed the Trial of Navigation.\n";
        return;
    }

    char move;

    cout << "\nVivi: Ready to find your way out? Let's go with the Trial of Navigation.\n";
    cout << "Vivi: Navigate through the maze using w (up), a (left), s (down), d (right).\n";
    cout << "Vivi: You must follow the 'o' path and avoid the '#' walls.\n";

    //until player reaches exit [8][7]
    while (!(playerX == 8 && playerY == 7)) {
        createMaze();
        cout << "<Enter your move (w/a/s/d):>\n";
        cin >> move;
        movePlayer(move);
    }

    cout << "Vivi: Congratulations! We reached the end of the maze!\n";
    createMaze(); // Show final position
    completed = true;
}

//Check trial completion status
bool NavigationTrial::isCompleted() const {
    return completed;
}
