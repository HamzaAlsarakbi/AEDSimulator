#include "Patient.h"

/**
 * Constructs a Patient with a default age of 18 years old
 */
Patient::Patient()
: heart(new Heart())
{
    setAge(18);
}
Patient::~Patient() {
    delete heart;
}

bool Patient::shockable(){
    if(heart->getHeartRate() > 40){
        if(heart->getStatus() == VTACH || heart->getStatus() == VFIB){
            return true;
        }
        else{
            return false;
        }
    }
    else{ // pulse too weak or 0, non-shockable rhythm
        return false;
    }
}

bool Patient::cpr(double compressionDepth){
    if(compressionDepth >= minCompressionDepth || compressionDepth <= maxCompressionDepth){
        // heart should start stabilizing
            // basePulseTime start going towards 1000
            // pulseTimeVariance starts going towards 0
        return true;
    }
    else{
        return false;
    }
}

void Patient::reset(){

}