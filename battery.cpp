#include "battery.h"

/**
 * @brief Battery::Battery
 *
 * Basic constructor, all devices start with a charge of 100%.
 */
Battery::Battery()
{
    //init to 100, simulate full charge
    percentage = 100;
}

void Battery::set_percentage(int p){
    percentage = p;
}

int Battery::get_percentage(){
    return percentage;
}

/**
 * @brief Battery::has_enough_charge
 * @return whether the device has enough charge to perform a scan.
 */
bool Battery::has_enough_charge(){
    return percentage >= CHARGE_PER_SCAN;
}

//placeholder for now
Battery::~Battery(){}
