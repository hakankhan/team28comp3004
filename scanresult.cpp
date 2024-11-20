#include "scanresult.h"

ScanResult::ScanResult()
{

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
