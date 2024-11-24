#include "profile.h"

Profile::Profile()
{
    first_name = "";
    last_name = "";
    height = -1;
    weight = -1;
    birthday = QDate();
    country = "";
    history = NULL;
}

Profile::Profile(QString fname, QString lname, int h, int w, QDate bd, QString c, Records* h){
    first_name = fname;
    last_name = lname;
    height = h;
    weight = w;
    birthday = bd;
    country = c;
    history = h;
}

void Profile::set_first_name(QString f){
    first_name = f;
}

void Profile::set_last_name(QString l){
    last_name = l;
}

void Profile::set_height(int h){
    height = h;
}

void Profile::set_weight(int w){
    weight = w;
}

void Profile::set_birthday(QDate b){
    birthday = b;
}

void Profile::set_country(QString c){
    country = c;
}

QString Profile::get_first_name(){
    return first_name;
}

QString Profile::get_last_name(){
    return last_name;
}

int Profile::get_height(){
    return height;
}

int Profile::get_weight(){
    return weight;
}

QDate Profile::get_birthday(){
    return birthday;
}

QString Profile::get_country(){
    return country;
}

Records* Profile::get_history(){
    return history;
}

void Profile::set_history(Records* h){
    history = h;
}

//placeholder
Profile::~Profile(){}
