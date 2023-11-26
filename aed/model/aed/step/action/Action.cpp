#include "Action.h"

#include <utility>

Action::Action(ActionType type, std::string text)
: actionType(type), text(std::move(text)) {}