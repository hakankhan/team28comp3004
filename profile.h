#ifndef PROFILE_H
#define PROFILE_H
#include <QDateTime>
#include <QString>

class Profile
{
    public:
        Profile();
        Profile(QString, QString, int, int, QDateTime, QString);
        void set_first_name(QString);
        void set_last_name(QString);
        void set_height(int);
        void set_weight(int);
        void set_birthday(QDateTime);
        void set_country(QString);
        QString get_first_name();
        QString get_last_name();
        int get_height();
        int get_weight();
        QDateTime get_birthday();
        QString get_country();
        ~Profile();

    private:
        QString first_name;
        QString last_name;
        int height;
        int weight;
        QDateTime birthday;
        QString country;
};

#endif // PROFILE_H
