#include PHT.hpp

class PHT {
private:
  Adafruit_MS8607 ms8607;
  //const int PHT_SCL = 14;
  //const int PHT_SDA = 13; 

public:
  PHT() {
    // Constructor
    
  }

  void begin() {
    Wire.begin();
    if (!ms8607.begin()) {
      Serial.println("Failed to find MS8607 chip");
      while (1) { delay(10); }
    }
  }


  void setHumidityResolution(uint8_t resolution) {
    ms8607.setHumidityResolution(resolution);
  }

  void setPressureResolution(uint8_t resolution) {
    ms8607.setPressureResolution(resolution);
  }

  void readSensorData(float &temperature, float &pressure, float &humidity) {
    sensors_event_t temp, press, hum;
    ms8607.getEvent(&press, &temp, &hum);

    temperature = temp.temperature;
    pressure = press.pressure;
    humidity = hum.relative_humidity;
  }

  void outputSensorData()
  {
      float temperature, pressure, humidity;
      readSensorData(temperature, pressure, humidity);

      std::cout << "Temperature: " << temperature << " °C" << std::endl;
      std::cout << "Pressure: " << pressure << " hPa" << std::endl;
      std::cout << "Humidity: " << humidity << " %" << std::endl;

  }

};
