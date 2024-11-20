#include "records.h"

Records::Records()
{
    num_past_results = 0;
    //init collection to null pointer
    past_results = NULL;
}

ScanResult** Records::get_past_results(){
    return past_results;
}

void Records::add_result(ScanResult* s){
    past_results[num_past_results++] = s;
    sort_results();
}

/**
 * @brief Records::sort_results
 *
 * Function sorts ScanResults array 'past_results' by ScanResult->time_of_scan.
 * Also is responsible for dynamically reallocating room for new ScanResult objects
 * as the collection grows in size.
 *
 */
void Records::sort_results(){
    //todo
}

/**
 * @brief Records::~Records
 *
 * Deletes collection of past results.
 *
 */
Records::~Records(){
    for(int i = 0; i < num_past_results; i++){
        delete past_results[i];
    }
}
