#include "processor.h"

Processor::Processor()
{
    sensor = NULL;
}

/**
 * @brief Processor::perform_scan
 *
 * This function uses RaDoTech algorithms to generate a result based on sensor
 * data. This function is responsible for generating ScanResult objects, to be returned
 * for visual representation by the MainWindow object.
 *
 * @return ScanResult, the result of the scan
 */
ScanResult* Processor::perform_scan(){
    //todo
}

Sensor* Processor::get_sensor(){
    return sensor;
}

void Processor::set_sensor(Sensor* s){
    sensor = s;
}

/**
 * @brief Processor::~Processor
 *
 * Delete the sensor object if it is allocated.
 *
 */
Processor::~Processor(){
    if(sensor != NULL){
        delete sensor;
    }
}
