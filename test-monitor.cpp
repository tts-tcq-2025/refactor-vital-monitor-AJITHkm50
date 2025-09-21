#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include "./monitor.h"

void testVitalsOk() {
    // All vitals okay
    assert(vitalsOk(98.0f, 80.0f, 95.0f) == 1);  //  All vitals okay
    // Edge cases
    assert(vitalsOk(102.1f, 80.0f, 95.0f) == 0);  //  High temp
    assert(vitalsOk(94.9f, 80.0f, 95.0f) == 0);  //  Low temp
    assert(vitalsOk(98.0f, 59.9f, 95.0f) == 0);  //  Low pulse
    assert(vitalsOk(98.0f, 100.1f, 95.0f) == 0);  //  High pulse
    assert(vitalsOk(98.0f, 80.0f, 89.9f) == 0);  //  Low SpO2
    // Multiple warnings
    assert(vitalsOk(94.0f, 101.0f, 85.0f) == 0);  //  Multiple warnings
    // Test getVitalWarnings
    std::vector<std::string> w;
    w = getVitalWarnings(98.0f, 80.0f, 95.0f);
    assert(w.empty());  //  No warnings
    w = getVitalWarnings(103.0f, 80.0f, 95.0f);
    assert(w.size() == 1 && w[0].find("high") != std::string::npos);  //  High temp warning
    w = getVitalWarnings(94.0f, 101.0f, 85.0f);
    assert(w.size() == 3);  //  Three warnings
    std::cout << "All vitals tests passed!" << std::endl;
}

int main() {
    testVitalsOk();
    return 0;
}






