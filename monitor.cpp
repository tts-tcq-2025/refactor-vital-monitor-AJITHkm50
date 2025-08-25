#include "monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

// Constants for acceptable ranges
const float TEMP_MIN = 95.0f; // Minimum normal body temperature in Celsius
const float TEMP_MAX = 102.0f; // Maximum normal body temperature in Celsius
const float PULSE_MIN = 60.0f; // Minimum normal pulse rate
const float PULSE_MAX = 100.0f; // Maximum normal pulse rate
const float SPO2_MIN = 90.0f; // Minimum normal SpO2 percentage

// Function to check if temperature is critical
bool isTemperatureCritical(float temperature) {
    return temperature < TEMP_MIN || temperature > TEMP_MAX;
}

// Function to check if pulse rate is out of range
bool isPulseRateOutOfRange(float pulseRate) {
    return pulseRate < PULSE_MIN || pulseRate > PULSE_MAX;
}

// Function to check if SpO2 is low
bool isSpo2Low(float spo2) {
    return spo2 < SPO2_MIN;
}

// Function to blink a warning message
void blinkWarningMessage(const char* message) {
    cout << message << '\n';
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
    cout << "\r  \r" << flush;  // Clear the line after blinking
}

// Main function to check if all vitals are okay
int vitalsOk(float temperature, float pulseRate, float spo2) {
    int status = 0; // 0 means all vitals are okay

    // Check each vital sign and blink warning if necessary
    if (isTemperatureCritical(temperature)) {
        blinkWarningMessage("Temperature is critical!");
        return -1; // Temperature out of range
    }
    if (isPulseRateOutOfRange(pulseRate)) {
        blinkWarningMessage("Pulse Rate is out of range!");
        return -2; // Pulse rate out of range
    }
    if (isSpo2Low(spo2)) {
        blinkWarningMessage("Oxygen Saturation out of range!");
        return -3; // SpO2 out of range
    }

    return status; // All vitals are okay
}
