#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "scanresult.h"
#include "sensor.h"

#define GOOD_SENSOR_VALUE 10
#define NEUTRAL_SENSOR_VALUE 5
#define BAD_SENSOR_VALUE 3

//indexes for sensors
#define LH1 0
#define RH1 6
#define LH2 1
#define RH2 7
#define LH3 2
#define RH3 8
#define LH4 3
#define RH4 9
#define LH5 4
#define RH5 10
#define LH6 6
#define RH6 11
#define LF1 12
#define RF1 18
#define LF2 13
#define RF2 19
#define LF3 14
#define RF3 20
#define LF4 15
#define RF4 21
#define LF5 16
#define RF5 22
#define LF6 17
#define RF6 23


class ScanResult;
class Sensor;

class Processor
{
    public:
        Processor();
        ScanResult* perform_scan();
        Sensor* get_sensor();
        void set_sensor(Sensor *);
        ~Processor();
    private:
        Sensor* sensor;
        status* get_sensor_data(status*);
};

#endif // PROCESSOR_H
