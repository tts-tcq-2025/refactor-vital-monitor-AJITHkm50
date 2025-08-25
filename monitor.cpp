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

// Function to check if the temperature is critical
bool isCriticalTemperature(float currentTemperature) {
    return currentTemperature > TEMP_MAX || currentTemperature < TEMP_MIN;
}

// Function to check if the pulse rate is out of range
bool isPulseRateOutOfRange(float currentPulseRate) {
    return currentPulseRate < PULSE_MIN || currentPulseRate > PULSE_MAX;
}

// Function to check if SpO2 is low
bool isLowSpo2(float currentSpo2) {
    return currentSpo2 < SPO2_MIN;
}

// Function to blink a warning message
void blinkWarningMessage(const char* warningMessage) {
    cout << warningMessage << '\n';
    for (int i = 0; i < 3; i++) { // Reduced the number of blinks to 3
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
    cout << "\r  \r" << flush;  // Clear the line after blinking
}

// Function to check if all vitals are okay
int vitalsOk(float temperature, float pulseRate, float spo2) {
    // Check all vitals in a single decision point
    if (isCriticalTemperature(temperature)) {
        blinkWarningMessage("Temperature is critical!");
        return -1; // Temperature out of range
    }
    if (isPulseRateOutOfRange(pulseRate)) {
        blinkWarningMessage("Pulse Rate is out of range!");
        return -2; // Pulse rate out of range
    }
    if (isLowSpo2(spo2)) {
        blinkWarningMessage("Oxygen Saturation out of range!");
        return -3; // SpO2 out of range
    }

    return 0; // All vitals are okay
}
