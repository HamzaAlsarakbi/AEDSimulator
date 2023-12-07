#include <gtest/gtest.h>
#include "../model/patient/heart/pulse/Pulse.h"

using namespace std::chrono;
// is not vtach test
TEST(PulseTest, notVtach) {
    // Setup test data
    Pulse pulseObject(milliseconds(0), false);

    // Check the results
    ASSERT_EQ(pulseObject.isVtach(), false);
    ASSERT_EQ(pulseObject.getTime(), milliseconds(0));
}

// is vtach test
TEST(PulseTest, vTach) {
    // Setup test data
    Pulse pulseObject(milliseconds(0), true);

    // Check the results
    ASSERT_EQ(pulseObject.isVtach(), true);
    ASSERT_EQ(pulseObject.getTime(), milliseconds(0));
}