#include "Adafruit_ICM20X.h"
#include "Adafruit_ICM20948.h"
#include <iostream>

class IMU{
private:
    Adafruit_ICM20948 icm20948;
    int sda_pin, scl_pin;
public:
    IMU(int sda_pin, int scl_pin);
    
    void begin();

    void printSensorData();
    
};