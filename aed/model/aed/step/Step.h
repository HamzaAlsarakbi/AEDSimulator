#ifndef AED_STEP_H
#define AED_STEP_H

#include <iostream>
#include <vector>
#include <string>
#include "../components/display/Display.h"
#include "../step/action/Action.h"

using namespace std;

class Step {
public:
    // Constructor and desructor
    Step(string prompt, Display* display, bool autoAdvance, vector<Action*> actions);
    ~Step();
    
    // Getters and Setters
    Step* next();
    Display* getDisplay();
    bool getIsOn();
    string getPrompt();
    bool isAuto();
    vector<Action*> getActions();
    void setNextStep(Step* next);

    // Step functionality
    void turnOn();
    void turnOff();

private:
    bool isOn;
    string prompt;
    Step* nextStep;
    Display* display;
    vector<Action*> actions;
    bool autoAdvance; // automatically move to the next step
};

#endif // AED_STEP_H
