#ifndef PROFILE_H
#define PROFILE_H
#include <QDate>
#include <QString>
#include "records.h"

class Profile
{
    public:
        Profile();
        Profile(QString, QString, int, int, QDate, Records*, int);
        void set_first_name(QString);
        void set_last_name(QString);
        void set_height(int);
        void set_weight(int);
        void set_birthday(QDate);
        QString* get_first_name();
        QString* get_last_name();
        int get_height();
        int get_weight();
        QDate* get_birthday();
        Records* get_history();
        int get_id();
        void set_history(Records*);
        void add_result(ScanResult*);
        ~Profile();

    private:
        QString first_name;
        QString last_name;
        int height;
        int weight;
        QDate birthday;
        Records* history;
        int id;
};

#endif // PROFILE_H
