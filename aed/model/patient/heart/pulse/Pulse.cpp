#include "Pulse.h"

/**
 * Creates a Pulse object
 * @param vtach true if it s a vtach pulse
 */
Pulse::Pulse(bool vtach):
vtach(vtach),
// time in **nanoseconds**
timestamp(high_resolution_clock::now().time_since_epoch().count()) {}