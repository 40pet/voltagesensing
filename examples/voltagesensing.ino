#include <voltsense.h>

const int Analog_channel_pin = 15;
int ADC_VALUE = 0;

// User-defined calibration points (ADC values and corresponding voltages)
const int numPoints = 32;
const int adcPoints[numPoints] = {320, 464, 511, 643 , 778, 899, 988, 1088, 1171, 1295, 1382, 1465, 1525, 1648, 1709, 1826, 1943, 2083, 2238, 2347, 2544, 2681, 2815, 2912, 2993, 3101, 3279, 3415, 3677, 3844, 4003, 4095};
const float voltagePoints[numPoints] = {1.3, 1.8, 2.0,2.4, 2.9, 3.3, 3.6, 3.9, 4.2, 4.6, 4.9, 5.0, 5.4, 5.8, 6.0, 6.4, 6.8, 7.2, 7.8, 8.2, 8.8, 9.3, 9.7, 10.0,10.3, 10.6, 11.0, 11.3, 11.8, 12.0, 12.3, 12.70};

Voltsense voltsense(adcPoints, voltagePoints, numPoints);

void setup() 
{
    Serial.begin(115200);
}

void loop() 
{
    ADC_VALUE = analogRead(Analog_channel_pin);
    
    // Calculate voltage using piecewise linear interpolation
    float voltage_value = voltsense.getVoltage(ADC_VALUE);
    
    // Print the voltage with 3 decimal places
    Serial.print("Voltage = ");
    Serial.print(voltage_value, 3);  // Adjusted to 3 decimal places
    Serial.println(" volts");
    
    delay(50);
}
