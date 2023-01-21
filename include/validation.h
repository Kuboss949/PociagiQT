#pragma once
#include <iostream>
#include <string>

#include "DateAndTime.h"

#define STR_LIMIT 30

using namespace std;

bool validateDateAndHour(string str, DateAndTime &obj);

template <typename T>
bool validateString(T value){
    if(value.size()>0&&value.size()<=STR_LIMIT){
        return true;
    }
    return false;
}

