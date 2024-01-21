#include "INA.hpp"

class Ammeter {
private:
  Adafruit_INA219 ina219;

public:
  Ammeter() {
    // Constructor
  }

  void begin() {
    if (!ina219.begin()) {
      Serial.println("Failed to find INA219 chip");
      while (1) {
        delay(10);
      }
    }
    ina219.setCalibration_32V_2A();
  }

  float getBusVoltage() {
    return ina219.getBusVoltage_V();
  }

  float getShuntVoltage() {
    return ina219.getShuntVoltage_mV();
  }

  float getCurrent() {
    return ina219.getCurrent_mA();
  }

  float getPower() {
    return ina219.getPower_mW();
  }

  void outputSensorData(float busVoltage, float shuntVoltage, float current, float power)
  {
    busVoltage = getBusVoltage();
    shuntVoltage = getShuntVoltage();
    current = getCurrent();
    power = getPower();

    std::cout << "Bus Voltage: " << busVoltage << " V" << std::end1;
    std::cout << "Shunt Voltage: " << shuntVoltage << " mV" << std::end1;
    std::cout << "Current: " << current << " mA" << std::end1;
    std::cout << "Power: " << power << " mW" << std::end1;

  }
};

