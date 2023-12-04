#include <iostream>
#include "Heart.h"
/**
 * Constructs a Heart object with the following properties
 * - qrsWidth: 1000 milliseconds ~= 60 BPM
 * - qrsWidthVariance: 0 milliseconds
 */
Heart::Heart()
    : threadActive(true), thread(&Heart::updateState, this), status(HEART_NORMAL),
      basePulseTime(milliseconds(1000)), pulseTimeVariance(milliseconds(0)), heartRate(-1),
      distribution(std::uniform_int_distribution<>(0, INT32_MAX))
{
    std::random_device rd;
    gen = std::default_random_engine(rd());
}
Heart::~Heart()
{
    threadActive = false;
    // wait for thread to finish
    thread.join();

    while (!pulses.empty())
    {
        delete pulses.at(pulses.size() - 1);
        pulses.pop_back();
    }
}

void Heart::setVtach()
{
    if (status == VFIB)
        return;
    status = VTACH;
}

void Heart::resetVtach()
{
    if (status == VFIB)
        return;
    status = HEART_NORMAL;
}

/**
 * Missing documentation!
 */
void Heart::shock()
{
    setBasePulseTime(1000); // set to default
    if(status == VTACH){
        resetVtach();
    }
    else if(status == VFIB){
        setPulseTimeVariance(0); // set to regular rhythm
    }
    else{
        return ;
    }

}
long long Heart::generatePulseDuration() {;
    long long positive = (distribution(gen)%2)*2-1;
    long long variance = pulseTimeVariance.count() == 0 ? 0 :
                         distribution(gen) % (pulseTimeVariance.count()+1) * positive;
    return basePulseTime.count() + variance;
}
void Heart::updateState()
{
    long long pulseDuration = 0; // override this value in the while loop, the default duration between pulses
    const long long tickRate = 100; // milliseconds

    auto lastTick = high_resolution_clock::now();
    long long totalElapsedTime = 0;
    bool isRegular = NULL;
    auto elapsedTimeSinceLastPulse = 0;
    while (threadActive)
    {
        const auto currentTick = high_resolution_clock::now();
        const auto elapsedTimeSinceLastTick = duration_cast<milliseconds>(currentTick - lastTick).count();
        elapsedTimeSinceLastPulse += elapsedTimeSinceLastTick;
        totalElapsedTime += duration_cast<milliseconds>(currentTick - lastTick).count();
        lastTick = currentTick;

        // Check if it's time for the next pulse
        // compare elapsed time since last pulse to pulse duration
        if (elapsedTimeSinceLastPulse >= pulseDuration)
        {
            elapsedTimeSinceLastPulse = 0;
            pulseDuration = generatePulseDuration();

            // Add a new pulse
            milliseconds timestamp = pulses.empty() ? milliseconds(0) : pulses.at(pulses.size()-1)->getTime() + milliseconds(pulseDuration);
            std::cout << "Creating new pulse at: " << std::chrono::duration_cast<std::chrono::milliseconds>(timestamp).count() << " ms" << std::endl;
            pulses.push_back(new Pulse(timestamp, getStatus() == VTACH));

            // Check regularity
            // -2 to exclude last duration comparison (accesses garbage)
            if(pulses.size() >= 2){
                for (int j = 0; j < pulses.size() - 1; j++) {
                    // Convert nanoseconds to milliseconds before calculating the difference
                    long long pulseTime1 = duration_cast<milliseconds>(nanoseconds(pulses[j]->getTime())).count();
                    long long pulseTime2 = duration_cast<milliseconds>(nanoseconds(pulses[j + 1]->getTime())).count();

                    // compare two pulses at a time
                    // check the difference in duration
                    long long pulseDurationDiff = pulseTime2 - pulseTime1;

                    std::cout << "Pulse Duration Difference: " << pulseDurationDiff << " ms" << std::endl;

                    // Define upper and lower limits for pulse duration
                    long long upperPulseLim = pulseDuration + 40;
                    long long lowerPulseLim = pulseDuration - 40;

                    // Check if duration is within limits
                    isRegular = pulseDurationDiff <= upperPulseLim && pulseDurationDiff >= lowerPulseLim;
                }
            }
            else{
                if(this->getStatus() == VTACH || this->getStatus() == HEART_NORMAL){
                    isRegular = true;

                    if(this->getStatus() == VTACH){
                        setVtach();
                    }
                }
                else{
                    isRegular = false;
                }
            }

            // Calculate heartRate
            if (isRegular)
            {
                // Use big-box method to calculate heart rate
                if(pulses.size() >= 2){
                    heartRate = 300 / (pulses[0]->getTime() - pulses[1]->getTime()).count();
                }
                else {
                    heartRate = -1;
                }
            }
            else
            {
                status = VFIB; // commenting this out makes heartNormalStatusTest to pass but status wrong for heartVfibTest
                // Use 6-second method to calculate heart rate
                heartRate = pulses.size() * 10;
            }
        }

        // remove pulses that are longer than 6 seconds
        for (auto it = pulses.rbegin(); it != pulses.rend();)
        {
            auto durationSincePulse = duration_cast<seconds>(milliseconds (totalElapsedTime)- (*it)->getTime());
            if (durationSincePulse.count() > 6)
            {
                // Convert reverse iterator to a normal iterator before erasing
                auto toErase = std::next(it).base();
                delete *toErase; // delete the pulse
                it = std::make_reverse_iterator(pulses.erase(toErase)); // convert back to reverse iterator
            }
            else
            {
                // ignore the pulse
                ++it;
            }
        }

        // Wait until the next tick
        std::this_thread::sleep_for(std::chrono::milliseconds(tickRate));
    }
}