#ifndef CONTROL_H
#define CONTROL_H
#include <processor.h>
#include <battery.h>
#include <profile.h>

#define MAX_PROFILES 5

class Processor;
class Battery;
class Profile;

/**
 * @brief The Control class
 *
 * The Control class is responsible for maintaining the state of
 * the device, and interfaces with all other classes to perform device
 * functions. The Control class holds the Processor, Battery and Profile
 * classes (see 'processor.h', 'battery.h', and 'profile.h' respectively).
 */
class Control
{
    public:
        Control();
        Battery* get_battery();
        Processor* get_processor();
        void add_profile(QString, QString, QDate, int, int);
        void delete_profile(int);
        void set_current_profile(int);
        bool more_than_one_profile();
        Profile* get_current_profile();
        Profile** get_profiles();
        void deplete_battery();
        ~Control();

    private:
        Profile* profiles[MAX_PROFILES];
        Profile* current_profile;
        Battery* battery;
        Processor* processor;
        int next_id;
};

#endif // CONTROL_H
