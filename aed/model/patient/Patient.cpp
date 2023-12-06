#include "Patient.h"

/**
 * Constructs a Patient with a default age of 18 years old
 */
Patient::Patient(PatientSCondition condition)
: heart(new Heart())
{
    setAge(18);
    std::random_device rd;
    gen = std::default_random_engine(rd());
    reset(condition);
}
Patient::~Patient() {
    delete heart;
}
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

bool Patient::shockable(){
    bool isCardiacArrest = (heart->getStatus() == VTACH || heart->getStatus() == VFIB);
    return (getHeartRate() > 120 && isCardiacArrest);
}

bool Patient::cpr(double compressionDepth){
    if(compressionDepth >= minCompressionDepth && compressionDepth <= maxCompressionDepth){
        long long basePulseTime = 60000/getHeartRate();
        long long pulseTimeApproachDistance = (abs(1000 - basePulseTime)) / 2;
        long long ptvApproachDistance = (abs(heart->getPulseTimeVariance())) / 2;
//        getHeartRate() < 60 ? basePulseTime += pulseTimeApproachDistance : basePulseTime -= pulseTimeApproachDistance;
        basePulseTime += pulseTimeApproachDistance * (getHeartRate() > 60 ? 1 : -1);
        heart->setBasePulseTime(basePulseTime);

        if(heart->getPulseTimeVariance() > 0){
            heart->setPulseTimeVariance(ptvApproachDistance);
        }
        return true;
    }
    return false;
}

void Patient::reset(PatientSCondition condition){
    std::uniform_int_distribution<> distribution;
    int random;
    switch(condition) {
        case PSC_ARISTOTLE:
            heart->setBasePulseTime(100000); // .6 BPM
            heart->setPulseTimeVariance(0);
            heart->setVtach(false);
            heart->setStatus(ARISTOTLE);
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
            distribution = std::uniform_int_distribution<>(500, 250); // [120-240] BPM
            heart->setBasePulseTime(distribution(gen));
            distribution = std::uniform_int_distribution<>(0, 60);
            random = distribution(gen);
            heart->setPulseTimeVariance(random);
            heart->setVtach(random == 0);
            heart->setStatus(random == 0 ? VTACH : VFIB);
            break;
        default:
            distribution = std::uniform_int_distribution<>(1000, 500); // [120-240] BPM
            heart->setBasePulseTime(distribution(gen));
            heart->setPulseTimeVariance(0);
            heart->setVtach(false);
            heart->setStatus(HEART_NORMAL);
            break;
    }
}
