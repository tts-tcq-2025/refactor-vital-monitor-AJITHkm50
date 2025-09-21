
#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

namespace {
    struct VitalResult {
        bool ok;
        std::string message;
    };

    VitalResult checkTemperature(float t) {
        if (t > 102.0f)
            return {false, "Temperature is too high!"};
        if (t < 95.0f)
            return {false, "Temperature is too low!"};
        return {true, ""};
    }

    VitalResult checkPulse(float p) {
        if (p < 60.0f)
            return {false, "Pulse Rate is too low!"};
        if (p > 100.0f)
            return {false, "Pulse Rate is too high!"};
        return {true, ""};
    }

    VitalResult checkSpo2(float s) {
        if (s < 90.0f)
            return {false, "Oxygen Saturation is too low!"};
        return {true, ""};
    }
}

std::vector<std::string> getVitalWarnings(float temperature, float pulseRate, float spo2) {
    std::vector<std::string> warnings;
    auto tempRes = checkTemperature(temperature);
    if (!tempRes.ok) warnings.push_back(tempRes.message);
    auto pulseRes = checkPulse(pulseRate);
    if (!pulseRes.ok) warnings.push_back(pulseRes.message);
    auto spo2Res = checkSpo2(spo2);
    if (!spo2Res.ok) warnings.push_back(spo2Res.message);
    return warnings;
}

void blinkWarningMessage(const std::string& warningMessage) {
    cout << warningMessage << '\n';
    sleep_for(seconds(2));
    cout << "\r  \r" << flush;
}

int vitalsOk(float temperature, float pulseRate, float spo2) {
    auto warnings = getVitalWarnings(temperature, pulseRate, spo2);
    if (!warnings.empty()) {
        blinkWarningMessage(warnings[0]); // Only blink first warning for now
        return 0;
    }
    return 1;
}
