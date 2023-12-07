#ifndef AED_PULSE_H
#define AED_PULSE_H

#include <chrono>

using namespace std::chrono;
class Pulse {
public:
    Pulse(milliseconds timestamp, bool vtach);

    // getters
    milliseconds getTime() const { return timestamp; }
    bool isVtach() const { return vtach; }
    // don't put setters here, no need
private:
    milliseconds timestamp;
    bool vtach;
};

#endif