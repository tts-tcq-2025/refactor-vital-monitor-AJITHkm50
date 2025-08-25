#include "VitalsMonitor.h"

// Constants for acceptable ranges
const float TEMP_MIN = 36.1f; // Minimum normal body temperature in Celsius
const float TEMP_MAX = 37.2f; // Maximum normal body temperature in Celsius
const float PULSE_MIN = 60.0f; // Minimum normal pulse rate
const float PULSE_MAX = 100.0f; // Maximum normal pulse rate
const float SPO2_MIN = 95.0f; // Minimum normal SpO2 percentage

// Function to check if temperature is within normal range
bool isTemperatureOk(float temperature) {
    return temperature >= TEMP_MIN && temperature <= TEMP_MAX;
}

// Function to check if pulse rate is within normal range
bool isPulseRateOk(float pulseRate) {
    return pulseRate >= PULSE_MIN && pulseRate <= PULSE_MAX;
}

// Function to check if SpO2 is within normal range
bool isSpo2Ok(float spo2) {
    return spo2 >= SPO2_MIN;
}

// Function to evaluate all vitals and return the status
int evaluateVitals(float temperature, float pulseRate, float spo2) {
    if (!isTemperatureOk(temperature)) {
        return -1; // Temperature out of range
    }
    if (!isPulseRateOk(pulseRate)) {
        return -2; // Pulse rate out of range
    }
    if (!isSpo2Ok(spo2)) {
        return -3; // SpO2 out of range
    }
    return 0; // All vitals are okay
}

// Main function to check if all vitals are okay
int vitalsOk(float temperature, float pulseRate, float spo2) {
    return evaluateVitals(temperature, pulseRate, spo2);
}
