#ifndef CONTROL_H
#define CONTROL_H
#include <processor.h>
#include <battery.h>
#include <profile.h>

#define MAX_PROFILES 5

class Processor;
class Battery;
class Profile;

class Control
{
    public:
        Control();
        Battery* get_battery();
        Processor* get_processor();
        void switch_to_profile_at_index(int);
        void set_profile_at_index(int, Profile *);
        Profile* get_profile_at_index(int);
        void deplete_battery();
        ~Control();

    private:
        Profile* profiles[MAX_PROFILES];
        Profile* current_profile;
        Battery* battery;
        Processor* processor;
};

#endif // CONTROL_H
