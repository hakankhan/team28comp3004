#include "control.h"

/**
 * @brief Control::Control
 *
 * Constructor for the Control class. Initalizes profiles array to null
 * values as the profiles are created by the user at runtime. Also initalizes
 * all other device elements.
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

Profile* Control::get_current_profile(){
    return current_profile;
}

Profile** Control::get_profiles(){
    return profiles;
}

/**
 * @brief Control::add_profile
 *
 * add_profile is a function which takes in user provided information,
 * and creates a new profile for the user, adding it to the array of Profile
 * objects (see 'profile.h').
 *
 * @param fname - The first name provided by the user
 * @param lname - The last name provided by the user
 * @param bd - The birthday provided by the user
 * @param h - The height provded by the user
 * @param w - The weight provided by the user
 */
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
    delete p;
}

/**
 * @brief Control::delete_profile
 *
 * delete_profile is a function which takes the id of a Profile (see 'profile.h')
 * as a parameter and deletes it from the Profiles array, while also deleting the
 * object to prevent memory leaks.
 *
 * @param id - The id of the Profile to be deleted
 */
void Control::delete_profile(int id){
    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i]->get_id() == id){
            delete profiles[i];
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

/**
 * @brief Control::set_current_profile
 *
 * set_current_profile sets the current_profile pointer to a specific
 * Profile (see 'profile.h') based on the id parameter passed to this
 * function.
 *
 * @param id - The id of the Profile to become the new current_profile
 */
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
 * @brief Control::deplete_battery
 *
 * deplete_battery is a function which decrements the battery percentage
 * when scans are performed.
 */
void Control::deplete_battery(){
    battery->set_percentage(battery->get_percentage() - CHARGE_PER_SCAN);
}

/**
 * @brief Control::more_than_one_profile
 *
 * more_than_one profile returns TRUE if there are more than
 * one Profile pointers (see 'profile.h') in the profiles array.
 *
 * @return TRUE if there are more than one non-null pointers in the
 * profiles array, FALSE otherwise
 */
bool Control::more_than_one_profile(){
    int count = 0;
    for(int i = 0; i < MAX_PROFILES; i++){
        if(profiles[i] != NULL){
            count++;
        }
    }
    return count > 1;
}

/**
 * @brief Control::~Control
 *
 * Delete all allocated Profile (see 'profile.h') objects
 * Delete Battery (see 'battery.h'), Processor (see 'processor.h') object
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
