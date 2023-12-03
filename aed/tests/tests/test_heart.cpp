#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "../model/patient/heart/Heart.h"

TEST(HeartTest, heartNormalStatusTest) {
    Heart heart;

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    while(heart.getPulsesCount() < 6) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ASSERT_EQ(heart.getStatus(), HEART_NORMAL);  // Expected status after running for a while
    ASSERT_EQ(heart.getHeartRate(), 60); // Assert heart rate is positive or as expected
}