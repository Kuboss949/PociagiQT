//
// Created by creaz on 09.01.2023.
//

#include "DateAndTime.h"
/**
 * This constructor sets default date as 01-01-2000 4:20
 */
DateAndTime::DateAndTime() {
    day=1;
    month=1;
    year=2000;
    hour=4;
    minute=20;
}

/**
 * This constructor sets all provided members in initialization list
 */
DateAndTime::DateAndTime(const int &day, const int &month, const int &year, const int &hour, const int &minute):day(day),month(month),year(year),hour(hour),minute(minute) {

}

/**
 * day getter
 */
int DateAndTime::getDay() const {
    return day;
}

/**
 * month getter
 */
int DateAndTime::getMonth() const {
    return month;
}

/**
 * year getter
 */
int DateAndTime::getYear() const {
    return year;
}

/**
 * hour getter
 */
int DateAndTime::getHour() const {
    return hour;
}

/**
 * minute getter
 */
int DateAndTime::getMinute() const {
    return minute;
}

/**
 * day setter
 */
void DateAndTime::setDay(int value) {
    day = value;
}

/**
 * month setter
 */
void DateAndTime::setMonth(int value) {
    month = value;
}

/**
 * year setter
 */
void DateAndTime::setYear(int value) {
    year = value;
}

/**
 * hour setter
 */
void DateAndTime::setHour(int value) {
    hour = value;
}

/**
 * minute setter
 */
void DateAndTime::setMinute(int value) {
    minute = value;
}

/**
 * This method converts class into a string in "DD-MM-YYYY HH:MM" format
 * If day, month, minute and hour are lower than 10, it writes 0 before their value
 */
string DateAndTime::toString() const{
    string tmp;
    if(day<10)
        tmp+="0";
    tmp+=to_string(day)+"-";
    if(month<10)
        tmp+="0";
    tmp+=to_string(month)+"-"+ to_string(year)+ " ";
    if(hour<10)
        tmp+="0";
    tmp+=to_string(hour)+":";
    if(minute<10)
        tmp+="0";
    tmp+=to_string(minute);

    return tmp;
}

/**
 * This method writes the values of DateAndTime class members into a binary file
 */
void DateAndTime::writeToBinFile(ostream &stream) {
    if(stream.good()){
        stream.write(reinterpret_cast<char*>(&day), sizeof(int));
        stream.write(reinterpret_cast<char*>(&month), sizeof(int));
        stream.write(reinterpret_cast<char*>(&year), sizeof(int));
        stream.write(reinterpret_cast<char*>(&hour), sizeof(int));
        stream.write(reinterpret_cast<char*>(&minute), sizeof(int));
    }
}


/**
 * This method reads the values of DateAndTime class members from a binary file
 */
void DateAndTime::readFromBinFile(ifstream &stream) {
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&day), sizeof(int));
        stream.read(reinterpret_cast<char*>(&month), sizeof(int));
        stream.read(reinterpret_cast<char*>(&year), sizeof(int));
        stream.read(reinterpret_cast<char*>(&hour), sizeof(int));
        stream.read(reinterpret_cast<char*>(&minute), sizeof(int));
    }
}


