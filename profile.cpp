#include "profile.h"

Profile::Profile()
{
    first_name = "";
    last_name = "";
    height = -1;
    weight = -1;
    birthday = QDate();
    history = NULL;
    id = -1;
}

Profile::Profile(QString fname, QString lname, int h, int w, QDate bd, Records* his, int i){
    first_name = fname;
    last_name = lname;
    height = h;
    weight = w;
    birthday = bd;
    history = his;
    id = i;
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

QString* Profile::get_first_name(){
    return &first_name;
}

QString* Profile::get_last_name(){
    return &last_name;
}

int Profile::get_height(){
    return height;
}

int Profile::get_weight(){
    return weight;
}

QDate* Profile::get_birthday(){
    return &birthday;
}

Records* Profile::get_history(){
    return history;
}

void Profile::set_history(Records* h){
    history = h;
}

int Profile::get_id(){
    return id;
}

//placeholder
Profile::~Profile(){}
