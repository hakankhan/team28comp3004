#include "sensor.h"

/**
 * @brief Sensor::Sensor
 *
 * Init sensor values to -1 value
 *
 */
Sensor::Sensor()
{
    for(int i = 0; i < 24; i++){
        sensors[i] = -1;
    }
}

void Sensor::set_value_at_index(int i, double v){
    sensors[i] = v;
}

double Sensor::get_value_at_index(int i){
    return sensors[i];
}

//placeholder
Sensor::~Sensor(){}
