#include "records.h"

Records::Records()
{
    num_past_results = 0;
}

vector<ScanResult*> Records::get_past_results(){
    return past_results;
}

void Records::add_result(ScanResult* s){
    past_results.push_back(s);
    num_past_results++;
}

int Records::get_num_past_results(){
    return num_past_results;
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
    past_results.clear();
}
