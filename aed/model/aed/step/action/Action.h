#ifndef AED_ACTION_H
#define AED_ACTION_H

#include <string>

enum ActionType {
    SHOUT_ARE_YOU_OK_A,
    CALL_FOR_HELP_A,
    ATTACH_PADS_A,
};

class Action {
public:
    Action(ActionType type, std::string text);

private:
    std::string text;
    ActionType actionType;
};


#endif //AED_ACTION_H