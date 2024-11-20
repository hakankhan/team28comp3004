#include "battery.h"

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

//placeholder for now
Battery::~Battery(){}
