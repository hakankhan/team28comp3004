#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "scanresult.h"
#include "sensor.h"

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
};

#endif // PROCESSOR_H
