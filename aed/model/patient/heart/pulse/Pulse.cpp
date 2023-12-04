#include "Pulse.h"

/**
 * Creates a Pulse object
 * @param timestamp the timestamp of the pulse in milliseconds
 * @param vtach true if it s a vtach pulse
 */
Pulse::Pulse(milliseconds timestamp, bool vtach): timestamp(timestamp), vtach(vtach) {}
