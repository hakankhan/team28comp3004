#ifndef SENSOR_H
#define SENSOR_H


class Sensor
{
    public:
        Sensor();
        void set_value_at_index(int, double);
        double get_value_at_index(int);
        ~Sensor();

    private:
        double sensors[24];
};

#endif // SENSOR_H
