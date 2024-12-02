#include "profile.h"

/**
 * @brief Profile::Profile
 *
 * Empty constructor for Profile class, initalize all values to
 * NULL or equivalent.
 */
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

/**
 * @brief Profile::Profile
 *
 * The constructor for the Profile class. Initalizes all values.
 *
 * @param fname - The first_name field
 * @param lname - The last_name field
 * @param h - The height field
 * @param w - The weight field
 * @param bd - The birthday field
 * @param his - The history field
 * @param i - The id field
 */
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

/**
 * @brief Profile::add_result
 *
 * add_result inserts a ScanResult object (see 'scanresult.h') into
 * the profile's Records object (see 'records.h').
 *
 * @param s - The ScanResult object to be inserted
 */
void Profile::add_result(ScanResult* s){
    if(history == NULL){
        history = new Records();
    }
    history->add_result(s);
}

/**
 * @brief Profile::get_result
 *
 * get_result returns a ScanResult object (see 'scanresult.h') held within
 * the Records object (see 'records.h') for the profile at a given index.
 *
 * @param index - The index of the desired result
 * @return - The result at the provided index
 */
ScanResult* Profile::get_result(int index){
    return history->get_past_results()[index];
}

Profile::~Profile(){
    delete history;
}
