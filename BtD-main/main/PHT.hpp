#include "Adafruit_MS8607.h"
#include "pinConfig.hpp"
#include <iostream>

#ifndef PHT_HPP;
#define PHT_HPP;

class PHT {
private:
  Adafruit_MS8607 ms8607;
  //const int PHT_SCL = 14;
  //const int PHT_SDA = 13; 

public:
  PHT();

  void begin();

  void setHumidityResolution(uint8_t resolution);

  void setPressureResolution(uint8_t resolution);

  void readSensorData(float &temperature, float &pressure, float &humidity);

  void printSensorData();

};

#endif


