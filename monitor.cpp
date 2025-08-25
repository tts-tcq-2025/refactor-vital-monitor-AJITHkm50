#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>  // for std::find_if

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Function to check if the temperature is critical
bool isCriticalTemperature(float currentTemperature) {
    return currentTemperature > 102.0f || currentTemperature < 95.0f;
}

// Function to check if the pulse rate is out of range
bool isPulseRateOutOfRange(float currentPulseRate) {
    return currentPulseRate < 60.0f || currentPulseRate > 100.0f;
}

// Function to check if SpO2 is low
bool isLowSpo2(float currentSpo2) {
    return currentSpo2 < 90.0f;
}

// Function to blink a warning message
void displayWarningMessage(const char* warningMessage) {
    cout << warningMessage << '\n';
    for (int i = 0; i <2; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
    cout << "\r  \r" << flush;  // Clear the line after blinking
}

// Function to check if all vitals are okay
int vitalsOk(float temperature, float pulseRate, float spo2) {
    struct VitalCheck {
        bool (*checkFunction)(float);
        float value;
        const char* message;
    };

    const VitalCheck vitalChecks[] = {
        { isCriticalTemperature, temperature, "Temperature is critical!" },
        { isPulseRateOutOfRange, pulseRate, "Pulse Rate is out of range!" },
        { isLowSpo2, spo2, "Oxygen Saturation out of range!" }
    };

    // Use std::find_if to check for any vital sign issues
    auto it = std::find_if(std::begin(vitalChecks), std::end(vitalChecks),
                           [](const VitalCheck& check) {
                               return check.checkFunction(check.value);
                           });

    if (it != std::end(vitalChecks)) {
        displayWarningMessage(it->message);
        return 0;  //  Indicates an issue with vital signs
    }
    return 1;  //  All vitals are okay
}
