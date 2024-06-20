#ifndef voltsense_h
#define voltsense_h

#include "Arduino.h"

class Voltsense
{
public:
    Voltsense(const int* adcPoints, const float* voltagePoints, int numPoints);
    float getVoltage(int adc);

private:
    const int* _adcPoints;
    const float* _voltagePoints;
    int _numPoints;
};

#endif
