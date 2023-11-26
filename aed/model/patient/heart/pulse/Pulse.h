#ifndef AED_PULSE_H
#define AED_PULSE_H

#include <chrono>

using namespace std::chrono;
class Pulse {
public:
    Pulse(bool vtach);

    // getters
    nanoseconds getTime() const { return timestamp; }
    bool isVtach() const { return vtach; }
    // don't put setters here, no need
private:
    nanoseconds timestamp;
    bool vtach;
};

#endif