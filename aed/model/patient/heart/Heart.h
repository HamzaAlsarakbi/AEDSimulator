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
    ASYSTOLE
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
    void setBasePulseTime(int newValue) { this->basePulseTime = milliseconds(newValue); }
    void setPulseTimeVariance(int newValue) { this->pulseTimeVariance = milliseconds(newValue); }
    void setVtach(bool vtach);
    int getPulsesCount() const { return pulses.size(); }
    long long getPulseTimeVariance() const {return pulseTimeVariance.count();};
    void shock();
    long long generatePulseDuration();
    PulseType getCurrentPulseType();
    long long getTotalTime() const { return totalElapsedTime; }
    std::vector<Pulse *> getPulses() const { return pulses; }
    void clearPulses();

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
    long long totalElapsedTime;
    void updateState();
};

#endif // AED_HEART_H
