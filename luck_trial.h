#ifndef LUCK_TRIAL_H
#define LUCK_TRIAL_H

#include "trial.h" //include base trial
using namespace std;

bool validateInput(int&);

class LuckTrial : public Trial {
private:
    int luckyNumber; //stores lucky number

public:
    bool completed = false; //flag to check completion status
    LuckTrial(string name); //Constructor
    void run(); //Run trial
    bool isCompleted() const;
};

#endif // LUCK_TRIAL_H
