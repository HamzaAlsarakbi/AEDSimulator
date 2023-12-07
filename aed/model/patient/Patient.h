#ifndef AED_PATIENT_H
#define AED_PATIENT_H


#include "heart/Heart.h"

enum PatientSCondition {
    PSC_NORMAL, PSC_SUB40, PSC_ARISTOTLE, PSC_HEART_ATTACK,
};
enum CompressionResult {
    COMP_GOOD, COMP_HARDER, COMP_SOFTER, COMP_SLOWER, COMP_FASTER
};
class Patient {
public:
    Patient(PatientSCondition condition);
    ~Patient();

    // NO NEED FOR A HEART GETTER
    int getHeartRate() { return this->heart->getHeartRate(); }
    int getAge() const { return age; }
    int getMinCompressionDepth() const { return minCompressionDepth; }
    int getMaxCompressionDepth() const { return maxCompressionDepth; }
    void setQrsWidth(int newValue) { this->heart->setBasePulseTime(newValue); }
    void setQrsWidthVariance(int newValue) { this->heart->setPulseTimeVariance(newValue); }
    void setAge(int age);
    bool shockable();
    void shock();
    bool cprAble();
    CompressionResult cpr(int); // returns true if compression was good, otherwise false
    void reset(PatientSCondition condition); // reset  heart status to normal. set pulseTimeVariance to 0 and set basePulseTime to 1000
    Heart* getHeart() {return heart;}

private:
    int age;
    int minCompressionDepth;
    int maxCompressionDepth;
    milliseconds prevCompression;
    Heart* heart;
    std::default_random_engine gen;
};


#endif //AED_PATIENT_H
