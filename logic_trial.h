#ifndef LOGIC_TRIAL_H
#define LOGIC_TRIAL_H

#include "trial.h" //include base trial
using namespace std;

bool validateInput(int&);

class LogicTrial : public Trial {
private:
    int matrix[3][3]; //3x3 matrix
    void printMatrix(); //Function to print matrix

public:
    bool completed = false; //flag to check completion status
    LogicTrial(string name); //constructor
    void run();
    bool isCompleted() const;
};

#endif // LOGIC_TRIAL_H
