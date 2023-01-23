#pragma once
#include <iostream>
#include <string>

#include "DateAndTime.h"

#define STR_LIMIT 30

using namespace std;
/**
 * @brief function that validates if given string is in "DD-MM-YYYY HH:MM" format to form a DateAndTime class
 * @param str String that we want to validate
 * @param obj a reference to object in which we want to store validated data
 * @return true if string is valid
 */
bool validateDateAndHour(string str, DateAndTime &obj);

/**
 * @brief this functions checks if given string or QString length is between 1 and STR_LIMIT
 * @tparam T The type of the string or QString to be validated
 * @param value the value that we want to validate
 * @return  true if given value meets terms
 */
template <typename T>
bool validateString(T value){
    if(value.size()>0&&value.size()<=STR_LIMIT){
        return true;
    }
    return false;
}

