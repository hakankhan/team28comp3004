#include "processor.h"

Processor::Processor()
{
    sensor = NULL;
}

/**
 * @brief Processor::perform_scan
 *
 * This function uses RaDoTech algorithms to generate a result based on sensor
 * data. This function is responsible for generating ScanResult objects, to be returned
 * for visual representation by the MainWindow object.
 * sensor_data : Array of 24 statuses (0-5 LH, 6-11 RH, 12-17 LF, 18-23 RF)
 *
 * @return ScanResult, the result of the scan
 */
ScanResult* Processor::perform_scan(){
    status* sensor_data = get_sensor_data();
    ScanResult* result = new ScanResult();

    //set lungs
    status value = sensor_data[LH1] > sensor_data[RH1] ? sensor_data[RH1] : sensor_data[LH1];
    result->set_lungs_status(value);

    //set pericardium
    value = sensor_data[LH2] > sensor_data[RH2] ? sensor_data[RH2] : sensor_data[LH2];
    result->set_pericardium_status(value);

    //set heart
    value = sensor_data[LH3] > sensor_data[RH3] ? sensor_data[RH3] : sensor_data[LH3];
    result->set_heart_status(value);

    //set small intestine
    value = sensor_data[LH4] > sensor_data[RH4] ? sensor_data[RH4] : sensor_data[LH4];
    result->set_small_intestine_status(value);

    //set lymph
    value = sensor_data[LH5] > sensor_data[RH5] ? sensor_data[RH5] : sensor_data[LH5];
    result->set_lymph_status(value);

    //set large intestine
    value = sensor_data[LH6] > sensor_data[RH6] ? sensor_data[RH6] : sensor_data[LH6];
    result->set_heart_status(value);

    //set spleen & pancreas
    value = sensor_data[LF1] > sensor_data[RF1] ? sensor_data[RF1] : sensor_data[LF1];
    result->set_spleen_status(value);
    result->set_pancreas_status(value);

    //set liver
    value = sensor_data[LF2] > sensor_data[RF2] ? sensor_data[RF2] : sensor_data[LF2];
    result->set_liver_status(value);

    //set kidney & adrenal glands
    value = sensor_data[LF3] > sensor_data[RF3] ? sensor_data[RF3] : sensor_data[LF3];
    result->set_kidney_status(value);
    result->set_adrenal_glands_status(value);

    //set bladder
    value = sensor_data[LF4] > sensor_data[RF4] ? sensor_data[RF4] : sensor_data[LF4];
    result->set_bladder_status(value);

    //set gall bladder
    value = sensor_data[LF5] > sensor_data[RF5] ? sensor_data[RF5] : sensor_data[LF5];
    result->set_gall_bladder_status(value);

    //set stomach
    value = sensor_data[LF6] > sensor_data[RF6] ? sensor_data[RF6] : sensor_data[LF6];
    result->set_stomach_status(value);

    return result;
}

status* Processor::get_sensor_data(){

    status sensor_data[24];

    for(int i = 0; i < 24; i++){
        double value = sensor->get_value_at_index(i);
        if(value > GOOD_SENSOR_VALUE){
            sensor_data[i] = GOOD;
            continue;
        }

        if(value > NEUTRAL_SENSOR_VALUE){
            sensor_data[i] = NEUTRAL;
            continue;
        }

        if(value > BAD_SENSOR_VALUE){
            sensor_data[i] = BAD;
            continue;
        }
    }

    return sensor_data;
}

Sensor* Processor::get_sensor(){
    return sensor;
}

void Processor::set_sensor(Sensor* s){
    sensor = s;
}

/**
 * @brief Processor::~Processor
 *
 * Delete the sensor object if it is allocated.
 *
 */
Processor::~Processor(){
    if(sensor != NULL){
        delete sensor;
    }
}
