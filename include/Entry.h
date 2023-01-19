#pragma once
#include "DateAndTime.h"
#include "Train.h"
#include "CargoTrain.h"
#include "PassengerTrain.h"
#include <iomanip>

using namespace std;

class Entry {
    DateAndTime arrival;
    DateAndTime departure;
    string destination;
    string fromWhere;
    int platformNo;
    Train *entryTrain;
public:
    Entry();

    Entry(const DateAndTime &arrival, const DateAndTime &departure, const string &fromWhere, const string &destination,
          int platformNo, Train *entryTrain);

    Entry(const Entry &entry);

    friend ostream& operator<<(ostream &lhs, const Entry &rhs);
    string operator[](int i);

    void getTrainInfo();
    void writeToBinFile(ofstream &stream);
    void readFromBinFile(ifstream &stream);

    const DateAndTime &getArrival() const;

    void setArrival(const DateAndTime &arrival);

    const DateAndTime &getDeparture() const;

    void setDeparture(const DateAndTime &departure);

    const string &getFromWhere() const;

    void setFromWhere(const string &fromWhere);

    const string &getDestination() const;

    void setDestination(const string &destination);

    int getPlatformNo() const;

    void setPlatformNo(int platformNo);

    Train* getEntryTrain();


};