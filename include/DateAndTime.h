#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/**
 * @class DateAndTime
 * @brief Class which contains information about date and hour
 */
class DateAndTime {
    /**
     * @property day
     * @brief Date day
     */
    int day;
    /**
     * @property month
     * @brief Date month
     */
    int month;
    /**
     * @property year
     * @brief Date year
     */
    int year;
    /**
     * @property hour
     * @brief Date hour
     */
    int hour;
    /**
     * @property minute
     * @brief Date minute
     */
    int minute;
public:
    /**
     * @brief Base constructor which assigns default values to class members
     */
    DateAndTime();
    /**
     * @brief Constructor with all members
     * @param day Date day
     * @param month Date month
     * @param year Date year
     * @param hour Date hour
     * @param minute Date minute
     */
    DateAndTime(const int &day, const int &month, const int &year, const int &hour, const int &minute);

    /**
     * @brief day getter
     * @return The value of day
     */
    int getDay() const;

    /**
     * @brief day setter
     * @param value The new value of the day
     */
    void setDay(int value);

    /**
     * @brief month getter
     * @return The value of month
     */
    int getMonth() const;

    /**
     * @brief month setter
     * @param value The new value of the month
     */
    void setMonth(int value);

    /**
     * @brief year getter
     * @return The value of year
     */
    int getYear() const;

    /**
     * @brief year setter
     * @param value The new value of the year
     */
    void setYear(int value);

    /**
     * @brief hour getter
     * @return The value of hour
     */
    int getHour() const;

    /**
     * @brief hour setter
     * @param value The new value of the hour
     */
    void setHour(int value);

    /**
     * @brief minute getter
     * @return The value of minute
     */
    int getMinute() const;

    /**
     * @brief minute setter
     * @param value The new value of the minute
     */
    void setMinute(int value);

    /**
     * @return string representation of date in "DD-MM-YYYY HH:MM" format
     */
    string toString() const;

    /**
     * @brief Function which writes DateAndTime object into binary file
     * @param stream reference to ostream where we want to write our object
     */
    void writeToBinFile(ostream &stream);

    /**
     * @brief Function which reads DateAndTime object into binary file
     * @param stream reference to istream from where we want to read our object
     */
    void readFromBinFile(ifstream &stream);
};


