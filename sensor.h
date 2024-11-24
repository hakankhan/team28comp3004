#ifndef SENSOR_H
#define SENSOR_H

/**
 * @brief The Sensor class
 *
 * Add better documentation later, but for now:
 * Sensor : Array of 24 doubles (0-5 LH, 6-11 RH, 12-17 LF, 18-23 RF)
 *
 */
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
