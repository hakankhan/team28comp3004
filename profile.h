#ifndef PROFILE_H
#define PROFILE_H
#include <QDate>
#include <QString>

class Profile
{
    public:
        Profile();
        Profile(QString, QString, int, int, QDate, QString);
        void set_first_name(QString);
        void set_last_name(QString);
        void set_height(int);
        void set_weight(int);
        void set_birthday(QDate);
        void set_country(QString);
        QString get_first_name();
        QString get_last_name();
        int get_height();
        int get_weight();
        QDate get_birthday();
        QString get_country();
        ~Profile();

    private:
        QString first_name;
        QString last_name;
        int height;
        int weight;
        QDate birthday;
        QString country;
};

#endif // PROFILE_H
