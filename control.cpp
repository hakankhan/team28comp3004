#include "control.h"

/**
 * @brief Control::Control
 *
 * Initalize device objects
 * All Profiles set to NULL as they have not been created by user yett
 * Create Battery, Processor objects
 *
 */
Control::Control()
{
    for(int i = 0; i < MAX_PROFILES; i++){
        profiles[i] = NULL;
    }

    battery = new Battery();
    processor = new Processor();
}

Battery* Control::get_battery(){
    return battery;
}

Processor* Control::get_processor(){
    return processor;
}

void Control::switch_to_profile_at_index(int i){
    current_profile = profiles[i];
}

void Control::set_profile_at_index(int i, Profile* p){
    profiles[i] = p;
}

Profile* Control::get_current_profile(){
    return current_profile;
}

/**
 * @brief Control::perform_action
 *
 * The function which decrements the battery percentage when actions are performed
 *
 */
void Control::deplete_battery(){
    battery->set_percentage(battery->get_percentage() - 5);
    //todo, how much to decrement battery by? also maybe rename function
}

/**
 * @brief Control::~Control
 *
 * Delete all allocated Profile objects
 * Delete Battery, Processor object
 *
 */
Control::~Control(){
    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i] != NULL){
            delete profiles[i];
        }
    }

    delete battery;
    delete processor;
}
