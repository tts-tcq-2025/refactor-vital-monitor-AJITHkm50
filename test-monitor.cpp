#include <iostream>
#include <cassert>
#include "./monitor.h"

void testVitalsOk() {
    assert(vitalsOk(36.5f, 75.0f, 97.0f) == 1);  //  All vitals okay
    assert(vitalsOk(35.0f, 75.0f, 97.0f) == 0);  //  Low temperature
    assert(vitalsOk(102.5f, 75.0f, 97.0f) == 0);  //  High temperature
    assert(vitalsOk(36.5f, 55.0f, 97.0f) == 0);  // Low pulse rate
    assert(vitalsOk(36.5f, 105.0f, 97.0f) == 0); // High pulse rate
    assert(vitalsOk(36.5f, 75.0f, 89.0f) == 0);  // Low SpO2
    std::cout << "All vitals tests passed!" << std::endl;  // Use std::endl for flushing
}

int main() {
    testVitalsOk();
    return 0;
}

