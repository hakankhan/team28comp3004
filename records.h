#ifndef RECORDS_H
#define RECORDS_H
#include "scanresult.h"
#include <vector>
using namespace std;
class ScanResult;

/**
 * @brief The Records class
 *
 * The Records class is a collection of ScanResult objects (see 'scanresult.h')
 * which is held by a Profile object (see 'profile.h').
 */
class Records
{
    public:
        Records();
        vector<ScanResult*> get_past_results();
        void add_result(ScanResult *);
        int get_num_past_results();
        ~Records();
    private:
        int num_past_results;
        vector<ScanResult*> past_results;
};

#endif // RECORDS_H
