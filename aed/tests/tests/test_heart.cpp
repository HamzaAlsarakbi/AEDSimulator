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

TEST(HeartTest, heartVfibStatusTest) {
    Heart heart;

    heart.setPulseTimeVariance(200);

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    while(heart.getPulsesCount() < 6) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ASSERT_EQ(heart.getStatus(), VFIB);  // Expected status after running for a while
    std::cout << heart.getHeartRate() << std::endl; // Assert heart rate is positive or as expected
}

TEST(HeartTest, heartVtachStatusTest) {
    Heart heart;

    heart.setBasePulseTime(500);
    heart.setVtach();

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    while(heart.getPulsesCount() < 6) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ASSERT_EQ(heart.getStatus(), VTACH);  // Expected status after running for a while
    ASSERT_EQ(heart.getHeartRate(), 120); // Assert heart rate is positive or as expected
}