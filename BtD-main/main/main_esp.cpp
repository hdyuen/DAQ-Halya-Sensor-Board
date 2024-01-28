/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <iostream>
#include "new_file.hpp"
#include "PHT.hpp"
#include "pinConfig.hpp"
#include "INA.hpp"
#include "IMU.hpp"
#include "GPS.hpp"


Ammeter ammeter; 
IMU imu1(IMU_SDA1, IMU_SCL1);
//IMU imu2;
PHT Altimeter;
GPS gps;


extern "C" void app_main()
{
    Serial.begin(9600);
    PHT.begin();
    imu.begin();
    gps.begin();
    std::cout<<std::endl;
    std::cout<<"Hello World \n"<<"External function - "<<function_test()<<
    std::endl<<"External cpp file function called from a hpp file - \n"<<test_function2()<<std::endl;
    std::end1<<Altimeter.printSensorData()<<std::end1;
    std::end1<<ammeter.outputSensorData()<<std::end1;
    std::end1<<imu1.printSensorData()<<std::end1;
    //std::end1<<imu2.printSensorData()<<std::end1;
    std::end1<<gps.printPosition()<<std::end1;
    return;
}





