#ifndef SCANRESULT_H
#define SCANRESULT_H
#include <QDateTime>

enum status {GOOD = 1, NEUTRAL = 0, BAD = -1};

class ScanResult
{
    public:
        ScanResult();
        status get_stomach_status();
        status get_lungs_status();
        status get_heart_status();
        status get_small_intestine_status();
        status get_large_intestine_status();
        status get_spleen_status();
        status get_liver_status();
        status get_kidney_status();
        status get_bladder_status();
        status get_gall_bladder_status();
        status get_pericardium_status();
        status get_lymph_status();
        status get_pancreas_status();
        status get_adrenal_glands_status();
        void set_stomach_status(status);
        void set_lungs_status(status);
        void set_heart_status(status);
        void set_small_intestine_status(status);
        void set_large_intestine_status(status);
        void set_spleen_status(status);
        void set_liver_status(status);
        void set_kidney_status(status);
        void set_bladder_status(status);
        void set_gall_bladder_status(status);
        void set_pericardium_status(status);
        void set_lymph_status(status);
        void set_pancreas_status(status);
        void set_adrenal_glands_status(status);

        QDateTime get_time_of_scan();
        void set_time_of_scan(QDateTime);
        ~ScanResult();

    private:
        QDateTime time_of_scan;
        status stomach;
        status lungs;
        status heart;
        status small_intestine;
        status large_intestine;
        status spleen;
        status liver;
        status kidney;
        status bladder;
        status gall_bladder;
        status pericardium;
        status lymph;
        status pancreas;
        status adrenal_glands;
};

#endif // SCANRESULT_H
