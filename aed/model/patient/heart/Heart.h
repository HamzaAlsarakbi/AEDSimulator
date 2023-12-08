#ifndef AED_HEART_H
#define AED_HEART_H

#include <thread>
#include <vector>
#include <random>
#include "pulse/Pulse.h"

using namespace std::chrono;

enum HeartStatus
{
    HEART_NORMAL,
    VTACH,
    VFIB,
    ASYSTOLE,
    DEAD
};

class Heart
{
public:
    Heart();
    ~Heart();
    HeartStatus getStatus() const { return status; }
    void setStatus(HeartStatus hs) {this->status = hs;}
    int getHeartRate() const { return heartRate; }
    long long getBasePulseTime() const { return basePulseTime.count(); }
    void setBasePulseTime(int newValue);
    void setPulseTimeVariance(int newValue) { this->pulseTimeVariance = milliseconds(newValue); }
    int getPulsesCount() const { return pulses.size(); }
    long long getPulseTimeVariance() const {return pulseTimeVariance.count();};
    void shock();
    long long generatePulseDuration();
    PulseType getCurrentPulseType();
    void clearPulses();

private:
    bool threadActive;
    std::thread thread;
    HeartStatus status;
    std::vector<Pulse *> pulses;
    duration<int64_t, std::milli> basePulseTime; // time to next
    duration<int64_t, std::milli> pulseTimeVariance;
    long long nextPulseTime;
    long long lastPulseTime;
    std::default_random_engine gen;
    std::uniform_int_distribution<> distribution;
    int heartRate;
    void updateState();
};

#endif // AED_HEART_H
