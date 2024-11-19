#ifndef BATTERY_H
#define BATTERY_H


class Battery
{
    public:
        Battery();
        void set_percentage(int);
        int get_percentage();
        ~Battery();

    private:
        int percentage;
};

#endif // BATTERY_H
