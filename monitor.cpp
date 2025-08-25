#include "VitalsMonitor.h"

// Constants for acceptable ranges
const float TEMP_MIN = 36.1f; // Minimum normal body temperature in Celsius
const float TEMP_MAX = 37.2f; // Maximum normal body temperature in Celsius
const float PULSE_MIN = 60.0f; // Minimum normal pulse rate
const float PULSE_MAX = 100.0f; // Maximum normal pulse rate
const float SPO2_MIN = 95.0f; // Minimum normal SpO2 percentage

// Function to check if all vitals are okay
int vitalsOk(float temperature, float pulseRate, float spo2) {
    // Check all vitals in a single decision point
    if ((temperature < TEMP_MIN || temperature > TEMP_MAX) ||
        (pulseRate < PULSE_MIN || pulseRate > PULSE_MAX) ||
        (spo2 < SPO2_MIN)) {
        
        // Determine which vital sign is out of range
        if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
            return -1; // Temperature out of range
        }
        if (pulseRate < PULSE_MIN || pulseRate > PULSE_MAX) {
            return -2; // Pulse rate out of range
        }
        if (spo2 < SPO2_MIN) {
            return -3; // SpO2 out of range
        }
    }
    
    return 0; // All vitals are okay
}
