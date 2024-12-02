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
            for(int j = i; j < MAX_PROFILES - 1; j++){
                profiles[j] = profiles[j + 1];
            }
            profiles[MAX_PROFILES - 1] = NULL;
            if(current_profile->get_id() == id){
                for(int j = 0; j < MAX_PROFILES; j++){
                    if(profiles[j] != NULL){
                        current_profile = profiles[j];
                        return;
                    }
                }
            }
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

Profile* Control::get_current_profile(){
    return current_profile;
}

Profile** Control::get_profiles(){
    return profiles;
}


/**
 * @brief Control::perform_action
 *
 * The function which decrements the battery percentage when actions are performed
 *
 */
void Control::deplete_battery(){
    battery->set_percentage(battery->get_percentage() - CHARGE_PER_SCAN);
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

bool Control::more_than_one_profile(){
    int count = 0;
    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i] != NULL){
            count++;
        }
    }
    return count > 1;
}
