#ifndef TRIAL_H
#define TRIAL_H

#include <string>
using namespace std;

bool validateInput(int& input);

class Trial {
protected:
    string playerName;

public:
    Trial(string name); //Constructor
};

#endif // TRIAL_H