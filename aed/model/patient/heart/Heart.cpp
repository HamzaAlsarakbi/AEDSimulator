#include <iostream>
#include "Heart.h"

/**
 * Constructs a Heart object with the following properties
 * - qrsWidth: 1000 milliseconds ~= 60 BPM
 * - qrsWidthVariance: 0 milliseconds
 */
Heart::Heart()
: threadActive(true), thread(&Heart::updateState, this), status(HEART_NORMAL),
pulseTime(milliseconds(1000)), pulseTimeVariance(milliseconds(0)), heartRate(-1)
{}
Heart::~Heart() {
    threadActive = false;
    // wait for thread to finish
    thread.join();

    while(!pulses.empty()) {
        delete pulses.at(pulses.size() - 1);
        pulses.pop_back();
    }
}

/**
 * Missing documentation!
 */
void Heart::shock() {
    std::cout << "todo Heart::shock()" << std::endl;
}


void Heart::updateState() {
    long long pulseDuration; // override this value in the while loop
    const long long tickRate = 100; // milliseconds

    while(threadActive) {
        /**
         * Manage and update the Heart attributes here.
         *
         * I don't think we need mutexes here but watch out for race conditions and potentially
         * weird behaviour.
         *
         * 1. Check if the time until the next pulse has come
            * 1. Create a new pulse at the back of the array and remove the pulse at the front to maintain a size of 6
            * 2. Calculate the time until the next pulse (pulseTime +- [0, pulseTimeVariance])
            * 3. Update the heartRate
         */

        // wait until the next tick
        std::this_thread::sleep_for(std::chrono::milliseconds (tickRate));
    }
}