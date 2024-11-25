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
    next_id = 0;
}

Battery* Control::get_battery(){
    return battery;
}

Processor* Control::get_processor(){
    return processor;
}

void Control::add_profile(QString fname, QString lname, QDate bd, int h, int w){
    Profile* p = new Profile(fname, lname, h, w, bd, NULL, next_id++);

    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i] == NULL){
            profiles[i] = p;
            current_profile = p;
            return;
        }
    }

    qInfo("Max profiles made already");
}

void Control::delete_profile(int id){
    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i]->get_id() == id){
            profiles[i] = NULL;
            return;
        }
    }

    qInfo("Profile not found - delete profile");
}

void Control::set_current_profile(int id){
    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i]->get_id() == id){
            current_profile = profiles[i];
            return;
        }
    }

    qInfo("Profile not found - set current profile");
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
