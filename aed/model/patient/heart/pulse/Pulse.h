#ifndef AED_PULSE_H
#define AED_PULSE_H

#include <chrono>

enum PulseType
{
    PULSE_NORMAL,
    PULSE_VTACH,
    PULSE_VFIB,
    PULSE_ASYSTOLE
};
using namespace std::chrono;
class Pulse {
public:
    Pulse(milliseconds timestamp, PulseType pulseType);
    // getters
    milliseconds getTime() const { return timestamp; }
    PulseType getType() const { return pulseType; }
    // don't put setters here, no need
private:
    milliseconds timestamp;
    PulseType pulseType;
};

#endif