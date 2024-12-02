#include "records.h"

/**
 * @brief Records::Records
 *
 * Initalizes the collection, sets the number of results to 0.
 */
Records::Records()
{
    num_past_results = 0;
}

vector<ScanResult*> Records::get_past_results(){
    return past_results;
}

int Records::get_num_past_results(){
    return num_past_results;
}

/**
 * @brief Records::add_result
 *
 * add_result inserts a ScanResult pointer (see 'scanresult.h') into the
 * collection.
 *
 * @param s - The ScanResult pointer (see 'scanresult.h') to be inserted
 */
void Records::add_result(ScanResult* s){
    past_results.push_back(s);
    num_past_results++;
}

/**
 * @brief Records::~Records
 *
 * Deletes collection of past results.
 */
Records::~Records(){
    for(int i = 0; i < num_past_results; i++){
        delete past_results[i];
    }
    past_results.clear();
}
