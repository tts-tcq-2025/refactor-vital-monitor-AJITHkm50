#pragma once

#ifdef __cplusplus
#include <vector>
#include <string>
#endif

// Returns 1 if all vitals are OK, 0 otherwise
int vitalsOk(float temperature, float pulseRate, float spo2);

#ifdef __cplusplus
// Returns a vector of warning messages for abnormal vitals
std::vector<std::string> getVitalWarnings(float temperature, float pulseRate, float spo2);
#endif
