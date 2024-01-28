#include "IMU.hpp"

class IMU {

private:
    
public:
    IMU(int sda_pin, int scl_pin)
    {
        sda_pin = sda_pin;
        scl_pin = scl_pin;
    }

    
    void begin(){
        Wire.begin(sda_pin, scl_pin);
    }

    void printSensorData()
    {
        sensors_event_t accel, gyro, mag, temp;
        icm20948.getEvent(&accel, &gyro, &temp, &mag);

        float accelerationX = accel.acceleration.x;
        std::cout << "Acceleration X: " << accelerationX << " m/s^2" << std::endl;
        float accelerationY = accel.acceleration.y;
        std::cout << "Acceleration Y: " << accelerationY << " m/s^2" << std::endl;
        float accelerationZ = accel.acceleration.z;
        std::cout << "Acceleration Z: " << accelerationZ << " m/s^2" << std::endl;

        float magX = mag.magentic.x;
        std::cout << "Mag X: " << magX << " uT" << std::endl;
        float magY = mag.magnetic.y;
        std::cout << "Mag Y: " << magY << " uT" << std::endl;
        float magZ = mag.magnetic.z;
        std::cout << "Mag Z: " << magZ << " uT" << std::endl;

        float gyroX = gyro.gyro.x;
        std::cout << "Gyro X: " << gyroX << " radian/s" << std::endl;
        float gyroY = gyro.gyro.y;
        std::cout << "Gyro Y: " << gyroY << " radian/s" << std::endl;
        float gyroZ = gyro.gyro.z;
        std::cout << "Gyro Z: " << gyroZ << " radian/s" << std::endl;
    }
    
};