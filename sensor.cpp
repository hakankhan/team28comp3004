#include "sensor.h"

/**
 * @brief Sensor::Sensor
 *
 * Init sensor values to -1 (NULL) value.
 */
Sensor::Sensor()
{
    for(int i = 0; i < 24; i++){
        sensors[i] = -1;
    }
}

/**
 * @brief Sensor::set_value_at_index
 *
 * set_value_at_index sets the value at index i to value v.
 *
 * @param i - The index
 * @param v - The value
 */
void Sensor::set_value_at_index(int i, double v){
    sensors[i] = v;
}

/**
 * @brief Sensor::get_value_at_index
 *
 * get_value_at_index returns the value at index i.
 *
 * @param i - The index
 * @return - The value
 */
double Sensor::get_value_at_index(int i){
    return sensors[i];
}

//placeholder
Sensor::~Sensor(){}
