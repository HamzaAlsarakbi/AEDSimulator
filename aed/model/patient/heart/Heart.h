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
    VFIB
};

class Heart
{
public:
    Heart();
    ~Heart();
    HeartStatus getStatus() const { return status; }
    int getHeartRate() const { return heartRate; }
    void setBasePulseTime(int newValue) { this->basePulseTime = milliseconds(newValue); }
    void setPulseTimeVariance(int newValue) { this->pulseTimeVariance = milliseconds(newValue); }
    void setVtach();
    int getPulsesCount() const { return pulses.size(); }

    void resetVtach();
    void shock();
    long long generatePulseDuration();

private:
    bool threadActive;
    std::thread thread;
    HeartStatus status;
    std::vector<Pulse *> pulses;
    duration<int64_t, std::milli> basePulseTime; // time to next
    duration<int64_t, std::milli> pulseTimeVariance;
    std::default_random_engine gen;
    std::uniform_int_distribution<> distribution;
    int heartRate;
    void updateState();
};

#endif // AED_HEART_H
