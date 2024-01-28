#include "GPS.hpp"

class GPS {
public:
  GPS() {}

  void begin() {
    PA161S_GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
    PA161S_GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ);
    delay(1000);
  }

  void printPosition() {
    if (PA161S_GPS.fix) {
      std::cout << "Latitude: " << PA161S_GPS.latitudeDegrees << "°" << std::endl;
      std::cout << "Longitude: " << PA161S_GPS.longitudeDegrees << "°" << std::endl;
      std::cout << "Fix quality: " << (int)PA161S_GPS.fixquality << std::endl;
    } else {
      std::cout << "Waiting for GPS fix..." << std::endl;
    }
  }

private:

  
};