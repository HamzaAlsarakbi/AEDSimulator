#include <gtest/gtest.h>
#include "../model/patient/heart/pulse/Pulse.h"

using namespace std::chrono;
// is normal test
TEST(PulseTest, normal) {
    // Setup test data
    Pulse pulseObject(milliseconds(0), PULSE_NORMAL);

    // Check the results
    ASSERT_EQ(pulseObject.getType(), PULSE_NORMAL);
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

// is vfib test
TEST(PulseTest, vTach) {
    // Setup test data
    Pulse pulseObject(milliseconds(0), true);

    // Check the results
    ASSERT_EQ(pulseObject.isVtach(), true);
    ASSERT_EQ(pulseObject.getTime(), milliseconds(0));
}

// is asystole test
TEST(PulseTest, vTach) {
    // Setup test data
    Pulse pulseObject(milliseconds(0), true);

    // Check the results
    ASSERT_EQ(pulseObject.isVtach(), true);
    ASSERT_EQ(pulseObject.getTime(), milliseconds(0));
}