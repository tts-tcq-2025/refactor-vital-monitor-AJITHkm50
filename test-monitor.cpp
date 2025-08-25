#include <iostream>
#include <cassert>
#include "VitalsMonitor.h"

void testVitalsOk() {
    // Test normal values
    assert(vitalsOk(36.5f, 75.0f, 97.0f) == 0);  // All vitals okay

    // Test temperature out of range
    assert(vitalsOk(35.0f, 75.0f, 97.0f) == -1); // Low temperature
    assert(vitalsOk(38.0f, 75.0f, 97.0f) == -1); // High temperature

    // Test pulse rate out of range
    assert(vitalsOk(36.5f, 55.0f, 97.0f) == -2); // Low pulse rate
    assert(vitalsOk(36.5f, 105.0f, 97.0f) == -2); // High pulse rate

    // Test SpO2 out of range
    assert(vitalsOk(36.5f, 75.0f, 94.0f) == -3); // Low SpO2

    std::cout << "All vitals tests passed!" << std::endl; // Use std::endl for flushing
}

int main() {
    testVitalsOk();
    return 0;
}
