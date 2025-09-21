#pragma once

#include <vector>
#include <string>

// Returns 1 if all vitals are OK, 0 otherwise
int vitalsOk(float temperature, float pulseRate, float spo2);

// Returns a vector of warning messages for abnormal vitals

std::vector<std::string> getVitalWarnings(float temperature, float pulseRate, float spo2);

