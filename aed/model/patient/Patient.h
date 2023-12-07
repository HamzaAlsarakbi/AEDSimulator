#ifndef AED_PATIENT_H
#define AED_PATIENT_H


#include "heart/Heart.h"

enum PatientSCondition {
    PSC_NORMAL, PSC_SUB40, PSC_ARISTOTLE, PSC_HEART_ATTACK,
};
class Patient {
public:
    Patient(PatientSCondition condition);
    ~Patient();

    // NO NEED FOR A HEART GETTER
    int getHeartRate() { return this->heart->getHeartRate(); }
    void setQrsWidth(int newValue) { this->heart->setBasePulseTime(newValue); }
    void setQrsWidthVariance(int newValue) { this->heart->setPulseTimeVariance(newValue); }
    void setAge(int age);
    bool shockable();
    bool cpr(double); // returns true if compression was good, otherwise false
    void reset(PatientSCondition condition); // reset  heart status to normal. set pulseTimeVariance to 0 and set basePulseTime to 1000
    Heart* getHeart() {return heart;}

private:
    int age;
    double minCompressionDepth;
    double maxCompressionDepth;
    Heart* heart;
    std::default_random_engine gen;
};


#endif //AED_PATIENT_H
