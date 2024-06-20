#include "voltsense.h"

Voltsense::Voltsense(const int* adcPoints, const float* voltagePoints, int numPoints)
{
    _adcPoints = adcPoints;
    _voltagePoints = voltagePoints;
    _numPoints = numPoints;
}

float Voltsense::getVoltage(int adc)
{
    // Check boundaries
    if (adc <= _adcPoints[0])
        return _voltagePoints[0];
    if (adc >= _adcPoints[_numPoints - 1])
        return _voltagePoints[_numPoints - 1];
    
    // Find the interval
    int i = 0;
    while (adc > _adcPoints[i + 1])
        i++;
    
    // Perform linear interpolation
    float adc0 = _adcPoints[i];
    float adc1 = _adcPoints[i + 1];
    float voltage0 = _voltagePoints[i];
    float voltage1 = _voltagePoints[i + 1];
    
    return voltage0 + (voltage1 - voltage0) * (adc - adc0) / (adc1 - adc0);
}
