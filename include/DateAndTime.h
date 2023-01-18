#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class DateAndTime {
    int day;
    int month;
    int year;
    int hour;
    int minute;
public:
    DateAndTime();

    DateAndTime(const int &day, const int &month, const int &year, const int &hour, const int &minute);
    DateAndTime(const int &day, const int &month, const int &year);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    int getHour() const;

    int getMinute() const;

    void setDay(int value);

    void setMonth(int value);

    void setYear(int value);

    void setHour(int value);

    void setMinute(int value);

    friend ostream& operator<<(ostream &lhs, const DateAndTime &rhs);

    string toString();


    void writeToBinFile(ostream &stream);

    void readFromBinFile(ifstream &stream);



};


