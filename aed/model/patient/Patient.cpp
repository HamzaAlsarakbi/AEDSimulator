#include <iostream>
#include "Patient.h"

/**
 * @brief Constructs a Patient with a default age of 18 years old
 * 
 * @param condition (PatientSCondition) the starting condition of the patient
 */
Patient::Patient(PatientSCondition condition)
: heart(new Heart()), prevCompression(-1)
{
    setAge(18);
    std::random_device rd;
    gen = std::default_random_engine(rd());
    reset(condition);
}

/**
 * @brief Destroy the Patient:: Patient object
 * 
 */
Patient::~Patient() {
    delete heart;
}

/**
 * @brief Changes the age of the patient
 * 
 * @param age (int) the age of the patient
 */
void Patient::setAge(int age) {
    this->age = age;
    if(age > 8) {
        minCompressionDepth = 200;
        maxCompressionDepth = 240;
    } else {
        minCompressionDepth = 150;
        maxCompressionDepth = 200;
    }
}

/**
 * @brief Determines whether the heartrate is shockable or not
 * 
 * @return true (bool) The heartrate is shockable
 * @return false (bool) The heartrate is not shockable
 */
bool Patient::shockable(){
    bool isCardiacArrest = (heart->getStatus() == VTACH || heart->getPulseTimeVariance() > 0);
    return (getHeartRate() > 120 && isCardiacArrest);
}

/**
 * @brief Simulates the administration of a shock
 * 
 */
void Patient::shock() {
    if(!shockable()) return;
    heart->shock();
}

/**
 * @brief Determines whether the patient requires CPR
 * 
 * @return (bool) true The patient requires CPR
 * @return (bool) false The patient do not require CPR
 */
bool Patient::cprAble() {
    return getHeartRate() < 40 || getHeart()->getStatus() != HEART_NORMAL;
}

/**
 * @brief simulates 1 compression in CPR
 * 
 * @param compressionDepth (int) The depth of compression for CPR
 * @return CompressionResult (CompressionResult) The feedback to the CPR provided
 */
CompressionResult Patient::cpr(int compressionDepth){
    // Feedback on the depth of compression
    if(compressionDepth < minCompressionDepth) return COMP_HARDER;
    if(compressionDepth > maxCompressionDepth) return COMP_SOFTER;

    // Feedback on the speed of compression
    auto curTime = system_clock::now();
    milliseconds timestamp = duration_cast<milliseconds>(curTime.time_since_epoch());
    long long duration = (timestamp - prevCompression).count();
    if(prevCompression.count() > 0) {
        prevCompression = timestamp;
        // std::cout << "duration: " << duration << std::endl;
        if(duration > 700) {
            return COMP_FASTER;
        } else if(duration < 400) {
            return COMP_SLOWER;
        }
    }
    prevCompression = timestamp;

    // Otherwise, good compressions
    long long basePulseTime = heart->getBasePulseTime();
    long long pulseTimeApproachDistance = fmin(abs(1100 - basePulseTime) / 10, 1000);
    long long ptvApproachDistance = fmin(abs(heart->getPulseTimeVariance()) / 2, 5);
    basePulseTime += pulseTimeApproachDistance * (getHeartRate() > 60 ? 1 : -1);
    heart->setBasePulseTime(basePulseTime);

    if(heart->getPulseTimeVariance() > 0){
        heart->setPulseTimeVariance(ptvApproachDistance);
    }
    return COMP_GOOD;
}

/**
 * @brief Resets the condition of the patient to whatever the parameter takes in
 * 
 * @param condition (PatientSCondition) the new condition of the patient
 */
void Patient::reset(PatientSCondition condition){
    std::uniform_int_distribution<> distribution;
    int random;
    // safely transfer ownership before deletion to avoid segfaults
    Heart* temp = heart;
    heart = nullptr;
    delete temp;
    heart = new Heart();
    switch(condition) {
        case PSC_ASYSTOLE:
            heart->setBasePulseTime(60005); // .6 BPM
            heart->setPulseTimeVariance(0);
            heart->setVtach(false);
            heart->setStatus(ASYSTOLE);
            break;
        case PSC_SUB40:
            // BPM is not immediately < 40 because of the variance that could potentially go over 40, rendering
            //   the heart "normal"
            distribution = std::uniform_int_distribution<>(2539, 60000); // [1-23.63]BPM
            heart->setBasePulseTime(distribution(gen));
            distribution = std::uniform_int_distribution<>(0, 1000);
            random = distribution(gen);
            heart->setPulseTimeVariance(random);
            heart->setVtach(random == 0);
            heart->setStatus(random == 0 ? VTACH : VFIB);
            break;
        case PSC_HEART_ATTACK:
            distribution = std::uniform_int_distribution<>(310, 500); // [120-240] BPM
            heart->setBasePulseTime(distribution(gen));
            distribution = std::uniform_int_distribution<>(0, 60);
            random = distribution(gen);
            heart->setPulseTimeVariance(random);
            heart->setVtach(random == 0);
            heart->setStatus(random == 0 ? VTACH : VFIB);
            break;
        default:
            distribution = std::uniform_int_distribution<>(500, 1000); // [120-240] BPM
            heart->setBasePulseTime(distribution(gen));
            heart->setPulseTimeVariance(0);
            heart->setVtach(false);
            heart->setStatus(HEART_NORMAL);
            break;
    }
}