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

