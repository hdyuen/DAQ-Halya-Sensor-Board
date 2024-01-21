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

PHT Altimeter;
Ammeter ammeter;

extern "C" void app_main()
{
    Wire.begin(PHT_SDA, PHT_SCL);
    Wire.begin(INA_SDA, INA_SCL);
    std::cout<<std::endl;
    std::cout<<"Hello World \n"<<"External function - "<<function_test()<<
    std::endl<<"External cpp file function called from a hpp file - \n"<<test_function2()<<std::endl;
    std::end1<<Altimeter.printSensorData()<<std::end1;
    std::end1<<ammeter.outputSensorData()<<std::end1;
    return;
}





