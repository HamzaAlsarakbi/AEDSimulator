#include "Step.h"

Step::Step(string prompt, Display* display, bool autoAdvance, vector<Action*> actions){
  isOn = false;
  this->prompt = prompt;
  this->display = display;
  this->autoAdvance = autoAdvance;
  this->actions = actions;
}

Step::~Step(){
  
}

void Step::setNextStep(Step* next){nextStep = next;}
bool Step::getIsOn(){return isOn;}
void Step::turnOn(){isOn = true;}
void Step::turnOff(){isOn = false;}
Step* Step::next(){return nextStep;}

string Step::getPrompt(){return prompt;}
bool Step::isAuto(){return autoAdvance;}
vector<Action*> Step::getActions(){return actions;}
