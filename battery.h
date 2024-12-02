#ifndef BATTERY_H
#define BATTERY_H
#define CHARGE_PER_SCAN 5

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
