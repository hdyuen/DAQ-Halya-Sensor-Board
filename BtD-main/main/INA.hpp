#include "Adafruit_INA219.h"
#include <iostream>

class Ammeter{
private:

public:
    Ammeter();

    void begin();

    float getBusVoltage();
    float getShuntVoltage();
    float getCurrent();
    float getPower();

    void outputSensorData(float busVoltage, float shuntVoltage, float current, float power);

};