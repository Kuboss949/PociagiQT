#include "validation.h"
/**
 * this function checks if given string is in "DD-MM-YYYY HH:MM" format
 * firstly it checks the length of given string, then validates digits and symbols
 * in the next step function creates substrings out of given strings
 * then it converts them to numbers
 * checks if numbers are in good range
 * sets members of given DateAndTime object
 */
bool validateDateAndHour(string str, DateAndTime &obj) {
    int charCount=0;
    if(str.length()!=16 || str[6]==0)
        return false;
    for(auto i:str){
        if(isdigit(i)==0){
            if((i=='-' || i==':' || i==' ') && charCount<4){
                charCount++;
                continue;
            }
            return false;
        }
    }
    string dayStr, monthStr, yearStr, hourStr, minuteStr;
    dayStr=str[0]=='0' ? string()+str[1]:string()+str[0]+str[1];
    monthStr=str[3]=='0' ? string()+str[4]:string()+str[3]+str[4];
    yearStr=string()+str[6]+str[7]+str[8]+str[9];
    hourStr=str[11]=='0' ? string()+str[12]:string()+str[11]+str[12];
    minuteStr=str[14]=='0' ? string()+str[15]:string()+str[14]+str[15];
    int day, month, year, hour, minute;
    day=stoi(dayStr);
    month=stoi(monthStr);
    year=stoi(yearStr);
    hour=stoi(hourStr);
    minute=stoi(minuteStr);
    if(day < 1 || day>31 || day>30 && (month==4 || month==6 || month==9 || month==11) || day>29 && month==2)
        return false;
    if(month<1 || month>12)
        return false;
    if(year<2000 || year>3000)
        return false;
    if(hour>23 || minute>59)
        return false;

    obj.setDay(day);
    obj.setMonth(month);
    obj.setYear(year);
    obj.setHour(hour);
    obj.setMinute(minute);
    return true;
}
