#include <gtest/gtest.h>
#include "../model/patient/heart/pulse/Pulse.h"

std::chrono::nanoseconds getCurrentTimeInNanoseconds() {
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch());
}

// is not vtach test
TEST(PulseTest, notVtach) {
    // Setup test data
    Pulse pulseObject(false);

    // Call method to test
    auto isVtachResult = pulseObject.isVtach();
    auto getTimeResult = pulseObject.getTime();

    // Check the results
    ASSERT_EQ(false, isVtachResult);

    // Assuming getTime() returns time in nanoseconds
    // Check if the time is within a reasonable range (e.g., +/- 1 second)
    auto currentTime = getCurrentTimeInNanoseconds().count();
    ASSERT_TRUE(getTimeResult.count() >= currentTime - 1000000000 && getTimeResult.count() <= currentTime + 1000000000);
}

// is vtach test
TEST(PulseTest, vTach) {
    // Setup test data
    Pulse pulseObject(true);

    // Call method to test
    auto isVtachResult = pulseObject.isVtach();
    auto getTimeResult = pulseObject.getTime();

    // Check the results
    ASSERT_EQ(true, isVtachResult);

    // Check if the time is within a reasonable range (e.g., +/- 1 second)
    auto currentTime = getCurrentTimeInNanoseconds().count();
    ASSERT_TRUE(getTimeResult.count() >= currentTime - 1000000000 && getTimeResult.count() <= currentTime + 1000000000);
}