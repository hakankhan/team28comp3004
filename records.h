#ifndef RECORDS_H
#define RECORDS_H
#include "scanresult.h"
#include <vector>
using namespace std;
class ScanResult;

class Records
{
    public:
        Records();
        vector<ScanResult*> get_past_results();
        void add_result(ScanResult *);
        ~Records();
    private:
        int num_past_results;
        vector<ScanResult*> past_results;
};

#endif // RECORDS_H
