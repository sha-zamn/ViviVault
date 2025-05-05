#include "logic_trial.h"
#include <iostream>

using namespace std;

//Constructor for trial with defined matrix
LogicTrial::LogicTrial(string name) : Trial(name) {
    matrix[0][0] = 8; matrix[0][1] = 0; matrix[0][2] = 4;
    matrix[1][0] = 1; matrix[1][1] = 5; matrix[1][2] = 9;
    matrix[2][0] = 6; matrix[2][1] = 7; matrix[2][2] = 0;
}

//Print matrix with missing numbers
void LogicTrial::printMatrix() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matrix[i][j] == 0) //print predefined number
                cout << "? "; //print missing number
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//Function to run trial
void LogicTrial::run() {
    if (completed) {
        cout << "\nVivi: You've already completed the Trial of Logic.\n";
        return;
    }

    const int sum = 45; //sum of all number in 3x3 matrix
    const int numRows = 3;
    int constNum = sum / numRows; //sum in each row
    
    cout << "\nVivi: The Trial of Logic? You must be a smart one.\n";
    cout << "Vivi: Can you guess the missing numbers? There might be a pattern.\n";

    while (true) { //loop until correct numbers are input
        printMatrix(); //print matrix with missing numbers
        cout << "<Enter the two missing numbers:>\n";
        int inputOne, inputTwo;

        if (!validateInput(inputOne) || !validateInput(inputTwo)) continue;

        int missingOne = constNum - (matrix[0][0] + matrix[0][2]); //calculate missing numbers
        int missingTwo = constNum - (matrix[2][0] + matrix[2][1]);

        if (inputOne == missingOne && inputTwo == missingTwo) {
            cout << "Vivi: Too easy for you!\n";
            matrix[0][1] = missingOne;
            matrix[2][2] = missingTwo;
            printMatrix();
            completed = true; //trial passed
            return;
        } else {
            cout << "Vivi: That's not right. Have you tried adding each row or column?\n";
        }
    }
}

//cehck completion status
bool LogicTrial::isCompleted() const {
    return completed;
}
