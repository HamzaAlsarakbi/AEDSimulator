#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "../model/patient/heart/Heart.h"

TEST(HeartTest, heartPulseGenerator) {
    Heart heart;
    for(int basePulseTime = 100; basePulseTime < 2000; basePulseTime+= 100) {
        heart.setBasePulseTime(basePulseTime);
        for(int pulseTimeVariance = 0; pulseTimeVariance <= 120; pulseTimeVariance++) {
            heart.setPulseTimeVariance(pulseTimeVariance);
            for(int i = 0; i < (pulseTimeVariance+2)*2; i++) {
                long long pulseDuration = heart.generatePulseDuration();
//                std::cout << "pulseDuration with variance of " << pulseTimeVariance << ": (" << pulseDuration << ")" << std::endl;
                ASSERT_TRUE(pulseDuration <= (basePulseTime + pulseTimeVariance) && pulseDuration >= (basePulseTime - pulseTimeVariance));
            }
        }
    }


}
TEST(HeartTest, heartNormalStatusTest) {
    Heart heart;
    heart.setBasePulseTime(1000);
    heart.setPulseTimeVariance(0);

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds (6050));

    ASSERT_EQ(heart.getStatus(), HEART_NORMAL);  // Expected status after running for a while
    ASSERT_EQ(heart.getHeartRate(), 60); // Assert heart rate is positive or as expected
}

TEST(HeartTest, heartNormalStatusTest120) {
    Heart heart;
    heart.setBasePulseTime(500);
    heart.setPulseTimeVariance(0);

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds (6050));

    ASSERT_EQ(heart.getStatus(), HEART_NORMAL);  // Expected status after running for a while
    ASSERT_EQ(heart.getHeartRate(), 120); // Assert heart rate is positive or as expected
}

TEST(HeartTest, heartVfibStatusTest) {
    Heart heart;

    heart.setPulseTimeVariance(200);

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(6050));

    ASSERT_EQ(heart.getStatus(), VFIB);  // Expected status after running for a while
    std::cout << heart.getHeartRate() << std::endl; // Assert heart rate is positive or as expected
}

TEST(HeartTest, heartVtachStatusTest) {
    Heart heart;

    heart.setBasePulseTime(500);
    heart.(true);

    // Let the heart update for a while (aka put the test thread to sleep)
    std::cout << "waiting for pulses" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(6050));

    ASSERT_EQ(heart.getStatus(), VTACH);  // Expected status after running for a while
    ASSERT_EQ(heart.getHeartRate(), 120); // Assert heart rate is positive or as expected
}