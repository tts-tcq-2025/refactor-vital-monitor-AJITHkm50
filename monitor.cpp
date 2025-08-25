#include "VitalsMonitor.h"

// Constants for acceptable ranges
const float TEMP_MIN = 36.1f; // Minimum normal body temperature in Celsius
const float TEMP_MAX = 37.2f; // Maximum normal body temperature in Celsius
const float PULSE_MIN = 60.0f; // Minimum normal pulse rate
const float PULSE_MAX = 100.0f; // Maximum normal pulse rate
const float SPO2_MIN = 95.0f; // Minimum normal SpO2 percentage

// Function to check if all vitals are okay
int vitalsOk(float temperature, float pulseRate, float spo2) {
    int status = 0; // 0 means all vitals are okay

    // Check temperature
    if (temperature < TEMP_MIN || temperature > TEMP_MAX) {
        status = -1; // Temperature out of range
    }

    // Check pulse rate
    if (pulseRate < PULSE_MIN || pulseRate > PULSE_MAX) {
        status = (status == 0) ? -2 : status; // Pulse rate out of range
    }

    // Check SpO2
    if (spo2 < SPO2_MIN) {
        status = (status == 0) ? -3 : status; // SpO2 out of range
    }

    return status; // Return the status code
}
