#include "scanresult.h"

/**
 * @brief ScanResult::ScanResult
 *
 * Init all organs to NEUTRAL status
 *
 */
ScanResult::ScanResult()
{
    stomach = NEUTRAL;
    lungs = NEUTRAL;
    heart = NEUTRAL;
    small_intestine = NEUTRAL;
    large_intestine = NEUTRAL;
    spleen = NEUTRAL;
    liver = NEUTRAL;
    kidney = NEUTRAL;
    bladder = NEUTRAL;
    gall_bladder = NEUTRAL;
    pericardium = NEUTRAL;
    lymph = NEUTRAL;
    pancreas = NEUTRAL;
    adrenal_glands = NEUTRAL;
}

status ScanResult::get_stomach_status(){
    return stomach;
}

status ScanResult::get_lungs_status(){
    return lungs;
}
status ScanResult::get_heart_status(){
    return heart;
}
status ScanResult::get_small_intestine_status(){
    return small_intestine;
}

status ScanResult::get_large_intestine_status(){
    return large_intestine;
}

status ScanResult::get_spleen_status(){
    return spleen;
}

status ScanResult::get_liver_status(){
    return liver;
}

status ScanResult::get_kidney_status(){
    return kidney;
}

status ScanResult::get_bladder_status(){
    return bladder;
}

status ScanResult::get_gall_bladder_status(){
    return gall_bladder;
}

status ScanResult::get_pericardium_status(){
    return pericardium;
}

status ScanResult::get_lymph_status(){
    return lymph;
}

status ScanResult::get_pancreas_status(){
    return pancreas;
}

status ScanResult::get_adrenal_glands_status(){
    return adrenal_glands;
}

void ScanResult::set_stomach_status(status s){
    stomach = s;
}

void ScanResult::set_lungs_status(status l){
    lungs = l;
}

void ScanResult::set_heart_status(status h){
    heart = h;
}

void ScanResult::set_small_intestine_status(status si){
    small_intestine = si;
}

void ScanResult::set_large_intestine_status(status li){
    large_intestine = li;
}

void ScanResult::set_spleen_status(status s){
    spleen = s;
}

void ScanResult::set_liver_status(status l){
    liver = l;
}

void ScanResult::set_kidney_status(status k){
    kidney = k;
}
void ScanResult::set_bladder_status(status b){
    bladder = b;
}

void ScanResult::set_gall_bladder_status(status gb){
    gall_bladder = gb;
}

void ScanResult::set_pericardium_status(status p){
    pericardium = p;
}

void ScanResult::set_lymph_status(status l){
    lymph = l;
}

void ScanResult::set_pancreas_status(status p){
    pancreas = p;
}

void ScanResult::set_adrenal_glands_status(status a){
    adrenal_glands = a;
}

QDateTime ScanResult::get_time_of_scan(){
    return time_of_scan;
}

void ScanResult::set_time_of_scan(QDateTime t){
    time_of_scan = t;
}



//placeholder
ScanResult::~ScanResult(){}
