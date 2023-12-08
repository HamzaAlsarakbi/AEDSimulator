#include <iostream>
#include "Heart.h"

/**
 * @brief Constructs a Heart object with the following properties
 * @brief - qrsWidth: 1000 milliseconds ~= 60 BPM
 * @brief - qrsWidthVariance: 0 milliseconds
 */
Heart::Heart()
    : threadActive(true), thread(&Heart::updateState, this), status(ASYSTOLE),
      basePulseTime(milliseconds(1000)), pulseTimeVariance(milliseconds(0)), heartRate(-1), nextPulseTime(0),
      lastPulseTime(0), distribution(std::uniform_int_distribution<>(0, INT32_MAX))
{
    std::random_device rd;
    gen = std::default_random_engine(rd());
}

/**
 * @brief Destroy the Heart:: Heart object
 * 
 */
Heart::~Heart()
{
    threadActive = false;
    // wait for thread to finish
    std::cout << "waiting for heart thread to terminate" << std::endl;
    thread.join();
    while (!pulses.empty())
    {
        delete pulses.at(pulses.size() - 1);
        pulses.pop_back();
    }
}
/**
 * @brief Returns the status of the heart's pulse
 * 
 * @return PulseType (PulseStatus) The status of the heart pulse
 */
PulseType Heart::getCurrentPulseType() {
    return status == HEART_NORMAL ? PULSE_NORMAL :
    status == VTACH ? PULSE_VTACH :
    status == VFIB ? PULSE_VFIB : 
    PULSE_ASYSTOLE;
}

/**
 * @brief Administers shock
 * 
 */
void Heart::shock()
{
    if(status == VTACH){
        setBasePulseTime(1621); // set to around 37bpm, for CPR later
    }
    else if(status == VFIB){
        setBasePulseTime(1621); // set to around 37bpm, for CPR later
        setPulseTimeVariance(0); // set to regular rhythm
    }
    else{
        return ;
    }

}
/**
 * Sets the base pulse time and updates the time for the next pulse
 * @param newValue
 */
void Heart::setBasePulseTime(int newValue)  {
    if(status == DEAD) return;
    this->basePulseTime = milliseconds(newValue);
    nextPulseTime = generatePulseDuration() + lastPulseTime;
}

/**
 * @brief Creates the duration between one pulse to another
 * 
 * @return long long The Duration of the pulse
 */
long long Heart::generatePulseDuration() {;
    long long positive = (distribution(gen)%2)*2-1;
    long long variance = pulseTimeVariance.count() == 0 ? 0 :
                         distribution(gen) % (pulseTimeVariance.count()+1) * positive;
    return basePulseTime.count() + variance;
}

/**
 * @brief Function on a thread that constantly updates the state of the heart
 * @brief - It checks the regularity of the heart beat
 * @brief - It calculates the heart rate from pulse information
 * 
 */
void Heart::updateState()
{
    const long long tickRate = 10; // milliseconds

    auto lastTick = high_resolution_clock::now();
    bool isRegular = false;
    long long  pulseDuration = 0;
    long long totalElapsedTime = 0;
    long long flatlineTime = 0;
    while (threadActive)
    {
        const auto currentTick = high_resolution_clock::now();
        const auto elapsedTimeSinceLastTick = duration_cast<milliseconds>(currentTick - lastTick).count();
        totalElapsedTime += elapsedTimeSinceLastTick;
        lastTick = currentTick;
        if(heartRate == 0) {
            flatlineTime += elapsedTimeSinceLastTick;
            if(flatlineTime > 60000) {
                pulses.clear();
                basePulseTime = milliseconds(0);
                pulseTimeVariance = milliseconds(0);
                status = DEAD;
                threadActive = false;
                return;
            }
        } else {
            flatlineTime = 0;
        }


        // Check if it's time for the next pulse
        // compare elapsed time since last pulse to pulse duration
        if (totalElapsedTime >= nextPulseTime)
        {
            // accommodate for thread error
            lastPulseTime = nextPulseTime;
            totalElapsedTime = nextPulseTime;
            pulseDuration = generatePulseDuration();
            nextPulseTime = pulseDuration + totalElapsedTime;

            // Add a new pulse
//            std::cout << "["<< totalElapsedTime << "ms] Created a pulse at: " << totalElapsedTime << "ms, next pulse in " << pulseDuration <<  "ms, at " << nextPulseTime << ". Current HR: " << heartRate << std::endl;
            pulses.push_back(new Pulse(milliseconds(totalElapsedTime), getCurrentPulseType()));

            // Check regularity
            // -2 to exclude last duration comparison (accesses garbage)
            if(pulses.size() > 1){
                long long diff = pulses[1]->getTime().count() - pulses[0]->getTime().count();
                long long maxPt = diff;
                long long minPt = maxPt;
                for (unsigned long j = 2; j < pulses.size(); j++) {
                    diff = pulses[j]->getTime().count() - pulses[j-1]->getTime().count();
                    // Convert nanoseconds to milliseconds before calculating the difference
                    maxPt = diff > maxPt ? diff : maxPt;
                    minPt = diff < minPt ? diff : minPt;
                }
                isRegular = (maxPt - minPt) == 0;
//                if(!isRegular)
//                    std::cout << "Pulse is not regular " << std::endl;
            }

            // Calculate heartRate
            if (isRegular) {
                if(status == VFIB) status = HEART_NORMAL;
                // Use big-box method to calculate heart rate
                if(pulses.size() >= 2){
                    heartRate = (int) round(60000.0 / (double) (pulses[1]->getTime() - pulses[0]->getTime()).count());
                    status = heartRate == 0 ? ASYSTOLE : heartRate > 120 ? VTACH : HEART_NORMAL;
                } else {
                    heartRate = (int) round(60000.0 / (double) basePulseTime.count());
                    status = ASYSTOLE;
                }
            } else {
                heartRate = getBasePulseTime() < 10000 ? pulses.size()*10 :
                        pulses.size() >= 2 ? (int) round(60000.0 / (double) (pulses[1]->getTime() - pulses[0]->getTime()).count()) :
                        (int) round(60000.0 / (double) basePulseTime.count());
                status = heartRate == 0 ? ASYSTOLE : VFIB;
            }
        }

//        int removeDuration = getBasePulseTime() < 10000 ? 6 : 60;
        int removeDuration = 6;
        while (!pulses.empty()) {
            Pulse *curPulse = pulses.at(0);
            auto durationSincePulse = duration_cast<seconds>(milliseconds(totalElapsedTime) - curPulse->getTime());
            if (durationSincePulse.count() < removeDuration) break;
            delete curPulse;
            pulses.erase(pulses.begin());
        }

        // Wait until the next tick
        std::this_thread::sleep_for(std::chrono::milliseconds(tickRate));
    }
}

/**
 * @brief Resets the pulse and heart rate data
 * 
 */
void Heart::clearPulses() {
    while(!pulses.empty()) {
        delete pulses.at(pulses.size() - 1);
        pulses.pop_back();
    }
    status = ASYSTOLE;
    heartRate = 0;
    nextPulseTime = 0;
}
