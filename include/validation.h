#pragma once
#include <iostream>
#include <string>
#include "DateAndTime.h"

using namespace std;

bool validateDateAndHour(string str, DateAndTime &obj);

template <typename T>
bool validateString(T value){
    if(value.size()>0&&value.size()<31){
        return true;
    }
    return false;
}