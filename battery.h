#ifndef BATTERY_H
#define BATTERY_H
#define CHARGE_PER_SCAN 5

/**
 * @brief The Battery class
 *
 * The Battery class holds the information regarding the device's
 * battery, with a function to check if the battery has enough charge to
 * perform a scan.
 */
class Battery
{
    public:
        Battery();
        void set_percentage(int);
        int get_percentage();
        bool has_enough_charge();
        ~Battery();
    private:
        int percentage;
};

#endif // BATTERY_H
