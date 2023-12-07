#include <gtest/gtest.h>
#include "../model/patient/Patient.h"

class PatientTest : public ::testing::Test {
protected:
    Patient patient;

public:
    PatientTest(): patient(PSC_NORMAL) {};

protected:
    void SetHeartCondition(PatientSCondition condition, HeartStatus status, int bpt, int ptv) {
        patient.reset(condition);
        patient.getHeart()->setStatus(status);
        patient.getHeart()->setBasePulseTime(bpt);
        patient.getHeart()->setPulseTimeVariance(ptv);
    }
};

TEST_F(PatientTest, Shockable_VTACH_HighHeartRate) {
    SetHeartCondition(PSC_HEART_ATTACK, VTACH, 400, 0); // 150bpm
    std::this_thread::sleep_for(std::chrono::milliseconds (6050));
    ASSERT_TRUE(patient.shockable());
}


TEST_F(PatientTest, Shockable_VFIB_HighHeartRate) {
    // heartRate varies too much. but an estimated heartRate
    // defined in the system is important for identifying VFIB
    SetHeartCondition(PSC_HEART_ATTACK, VFIB, 400, 20); // 140 BPM

    std::this_thread::sleep_for(std::chrono::milliseconds (6050));
    ASSERT_TRUE(patient.getHeartRate() > 120);
    ASSERT_TRUE(patient.shockable());
    ASSERT_TRUE(patient.getHeart()->getStatus() == VFIB);
}

TEST_F(PatientTest, NotShockable_VTACH_LowHeartRate) {
    SetHeartCondition(PSC_NORMAL, VTACH, 600, 0); // 100bpm
    ASSERT_FALSE(patient.shockable());
}

TEST_F(PatientTest, NotShockable_VFIB_LowHeartRate) {
    SetHeartCondition(PSC_NORMAL, VFIB, 600, 200); // 100bpm
    ASSERT_FALSE(patient.shockable());
}

TEST_F(PatientTest, NotShockable_Normal_HighHeartRate) {
    SetHeartCondition(PSC_NORMAL, HEART_NORMAL, 375, 0); // 160bpm
    ASSERT_FALSE(patient.shockable());
}

TEST_F(PatientTest, NotShockable_Normal_LowHeartRate) {
    SetHeartCondition(PSC_NORMAL, HEART_NORMAL, 600, 0); // 100bpm
    ASSERT_FALSE(patient.shockable());
}

TEST_F(PatientTest, cpr_Normal_LowHeartRate) {
    SetHeartCondition(PSC_SUB40, HEART_NORMAL, 1539, 0); // 39bpm
    std::this_thread::sleep_for(std::chrono::milliseconds (6050));
    ASSERT_TRUE(patient.cpr(220));
    ASSERT_TRUE(patient.getHeart()->getBasePulseTime() < 1539);
}