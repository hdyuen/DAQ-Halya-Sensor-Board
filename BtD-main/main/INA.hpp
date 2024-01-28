#include "Adafruit_INA219.h"
#include "pinConfig.hpp"
#include <iostream>

class Ammeter{
private:
    Adafruit_INA219 ina219;

public:
    Ammeter();

    void begin();

    float getBusVoltage();
    float getShuntVoltage();
    float getCurrent();
    float getPower();

    void outputSensorData(float busVoltage, float shuntVoltage, float current, float power);

};