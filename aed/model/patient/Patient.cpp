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

bool Patient::cpr(){
    double rescuerCompressionDepth; // how am I going to be getting this?
    if(rescuerCompressionDepth >= minCompressionDepth || rescuerCompressionDepth <= maxCompressionDepth){
        return true;
    }
    else{
        return false;
    }
}

void Patient::reset(){// is this function supposed to call heart->resetVtach()?

}