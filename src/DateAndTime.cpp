//
// Created by creaz on 09.01.2023.
//

#include "DateAndTime.h"

DateAndTime::DateAndTime() {
    day=1;
    month=1;
    year=2000;
    hour=4;
    minute=20;
}

DateAndTime::DateAndTime(const int &day, const int &month, const int &year, const int &hour, const int &minute):day(day),month(month),year(year),hour(hour),minute(minute) {

}

ostream &operator<<(ostream &lhs, const DateAndTime &rhs) {
    if(rhs.day<10)
        lhs << "0";
    lhs << rhs.day << "-";
    if(rhs.month<10)
        lhs << "0";
    lhs << rhs.month << "-" << rhs.year << "  ";
    if(rhs.hour<10)
        lhs << "0";
    lhs << rhs.hour <<":";
    if(rhs.minute<10)
        lhs << "0";
    lhs << rhs.minute;
    return lhs;
}

int DateAndTime::getDay() const {
    return day;
}

int DateAndTime::getMonth() const {
    return month;
}

int DateAndTime::getYear() const {
    return year;
}

int DateAndTime::getHour() const {
    return hour;
}

int DateAndTime::getMinute() const {
    return minute;
}

void DateAndTime::setDay(int value) {
    day = value;
}

void DateAndTime::setMonth(int value) {
    month = value;
}

void DateAndTime::setYear(int value) {
    year = value;
}

void DateAndTime::setHour(int value) {
    hour = value;
}

void DateAndTime::setMinute(int value) {
    minute = value;
}

void DateAndTime::writeToBinFile(ostream &stream) {
    if(stream.good()){
        stream.write(reinterpret_cast<char*>(&day), sizeof(int));
        stream.write(reinterpret_cast<char*>(&month), sizeof(int));
        stream.write(reinterpret_cast<char*>(&year), sizeof(int));
        stream.write(reinterpret_cast<char*>(&hour), sizeof(int));
        stream.write(reinterpret_cast<char*>(&minute), sizeof(int));
    }
}

void DateAndTime::readFromBinFile(ifstream &stream) {
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&day), sizeof(int));
        stream.read(reinterpret_cast<char*>(&month), sizeof(int));
        stream.read(reinterpret_cast<char*>(&year), sizeof(int));
        stream.read(reinterpret_cast<char*>(&hour), sizeof(int));
        stream.read(reinterpret_cast<char*>(&minute), sizeof(int));
    }
}

DateAndTime::DateAndTime(const int &day, const int &month, const int &year):day(day),month(month),year(year) {
    hour=4;
    minute=20;
}

string DateAndTime::toString() {
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

bool DateAndTime::operator>=(const DateAndTime &rhs) {
    if(year>rhs.year || year==rhs.year && (month>rhs.month || month==rhs.month && day>rhs.day)){
        return true;
    }else if(year==rhs.year && month==rhs.month && day==rhs.day && (hour>rhs.hour || hour==rhs.hour && minute>rhs.minute)){
        return true;
    }else{
        return false;
    }
}


