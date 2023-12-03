#ifndef AED_PATIENT_H
#define AED_PATIENT_H


#include "model/patient/heart/Heart.h"

class Patient {
public:
    Patient();
    ~Patient();

    // NO NEED FOR A HEART GETTER
    int getHeartRate() { return this->heart->getHeartRate(); }
    void setQrsWidth(int newValue) { this->heart->setBasePulseTime(newValue); }
    void setQrsWidthVariance(int newValue) { this->heart->setPulseTimeVariance(newValue); }
    void setAge(double age);
    bool shockable();
    bool cpr(); // returns true if compression was good, otherwise false
    void reset();

private:
    int age;
    double minCompressionDepth;
    double maxCompressionDepth;
    Heart* heart;
};


#endif //AED_PATIENT_H
