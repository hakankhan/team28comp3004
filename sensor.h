#ifndef SENSOR_H
#define SENSOR_H

/**
 * @brief The Sensor class
 *
 * The Sensor class is a class which simulates RaDoTech sensors. These
 * are implented as an array of 24 doubles (which simulate the voltage
 * each sensor recieves).
 * The array is stored as such: (0-5 LH, 6-11 RH, 12-17 LF, 18-23 RF).
 *
 * See 'processor.h' for specific indecies.
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
