#ifndef RECORDS_H
#define RECORDS_H
#include <scanresult.h>

class ScanResult;

class Records
{
    public:
        Records();
        ScanResult** get_past_results();
        void add_result(ScanResult *);
        ~Records();
    private:
        int num_past_results;
        void sort_results();
        ScanResult** past_results;
};

#endif // RECORDS_H
