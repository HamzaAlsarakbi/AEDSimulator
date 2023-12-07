#include "Pulse.h"

/**
 * Creates a Pulse object
 * @param timestamp the timestamp of the pulse in milliseconds
 * @param pulseType the type of pulse it is, taken from the heart's current status
 */
Pulse::Pulse(milliseconds timestamp, PulseType pulseType): timestamp(timestamp), pulseType(pulseType) {}
