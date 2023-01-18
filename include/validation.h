#pragma once
#include <iostream>
#include <string>
#include "DateAndTime.h"

using namespace std;

bool validateDate(string str, DateAndTime &obj);

bool validateHour(string str, DateAndTime &obj);

bool validateDateAndHour(string str, DateAndTime &obj);
