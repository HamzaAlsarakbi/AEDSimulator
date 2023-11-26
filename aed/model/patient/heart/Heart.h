#ifndef AED_HEART_H
#define AED_HEART_H

#include <thread>
#include <vector>
#include "model/patient/heart/pulse/Pulse.h"

using namespace std::chrono;

enum HeartStatus {
    HEART_NORMAL, VTACH, VFIB
};

class Heart {
public:
    Heart();
    ~Heart();
    HeartStatus getStatus() const { return status; }
    int getHeartRate() const { return heartRate; }

    void setVtach(int vtach) { this->vtach = vtach; }
    void setPulseTime(int newValue) { this->pulseTime = milliseconds(newValue); }
    void setPulseTimeVariance(int newValue) { this->pulseTimeVariance = milliseconds(newValue); }
    void shock();


private:
    bool threadActive;
    std::thread thread;
    HeartStatus status;
    std::vector<Pulse*> pulses;
    duration<int64_t, std::milli> pulseTime;
    duration<int64_t, std::milli> pulseTimeVariance;
    int heartRate;
    void updateState();
};


#endif //AED_HEART_H
