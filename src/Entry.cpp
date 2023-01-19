//
// Created by creaz on 09.01.2023.
//

#include "Entry.h"


Entry::Entry(const DateAndTime &arrival, const DateAndTime &departure, const string &fromWhere,
             const string &destination, int platformNo, Train *entryTrain) : arrival(arrival), departure(departure),
                                                                        fromWhere(fromWhere), destination(destination),
                                                                        platformNo(platformNo), entryTrain(entryTrain) {}

Entry::Entry() {
    arrival=DateAndTime();
    departure=DateAndTime();
    destination="";
    fromWhere="";
    platformNo=0;
    entryTrain=nullptr;
}

ostream &operator<<(ostream &lhs, const Entry &rhs) {
    lhs<< rhs.arrival << "\t" << rhs.departure << "\t" << rhs.destination << "\t" << rhs.fromWhere << "\t" << rhs.platformNo << "\t"<< rhs.entryTrain->getName() << endl;
    return lhs;
}

void Entry::writeToBinFile(ofstream &stream){
    arrival.writeToBinFile(stream);
    departure.writeToBinFile(stream);
    if(stream.good()){
        int tmpSize = destination.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&destination[0], tmpSize);

        tmpSize = fromWhere.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&fromWhere[0], tmpSize);

        stream.write(reinterpret_cast<char*>(&platformNo), sizeof(platformNo));
    }
    int type;
    if (CargoTrain* cargoTrain = dynamic_cast<CargoTrain*>(entryTrain)) {
        type=2;
    } else if (PassengerTrain* passengerTrain = dynamic_cast<PassengerTrain*>(entryTrain)) {
        type=1;
    } else {
        type=0;
    }
    stream.write(reinterpret_cast<char*>(&type), sizeof(int));
    entryTrain->writeToBinFile(stream);
}

void Entry::readFromBinFile(ifstream &stream) {
    int tmpSize;
    arrival.readFromBinFile(stream);
    departure.readFromBinFile(stream);
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        destination.resize(tmpSize);
        stream.read(&destination[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        fromWhere.resize(tmpSize);
        stream.read(&fromWhere[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&platformNo), sizeof(platformNo));
    }
    int type;
    stream.read(reinterpret_cast<char*>(&type), sizeof(int));
    if(entryTrain!= nullptr)
        delete entryTrain;
    if(type==0){
        entryTrain=new Train();
    }else if(type==1){
        entryTrain=new PassengerTrain();
    }else {
        entryTrain = new CargoTrain();
    }
    entryTrain->readFromBinFile(stream);
}

void Entry::getTrainInfo() {
    entryTrain->print();
}






Entry::Entry(const Entry &entry) {
    this->arrival=entry.arrival;
    this->departure=entry.departure;
    this->fromWhere=entry.fromWhere;
    this->destination=entry.destination;
    this->platformNo=entry.platformNo;
    if (CargoTrain* cargoTrain = dynamic_cast<CargoTrain*>(entry.entryTrain)) {
        this->entryTrain = new CargoTrain();
    } else if (PassengerTrain* passengerTrain = dynamic_cast<PassengerTrain*>(entry.entryTrain)) {
        this->entryTrain = new PassengerTrain();
    } else {
        this->entryTrain= new Train();
    }

    *this->entryTrain=*entry.entryTrain;



}

string Entry::operator[](int i) {
    if(i<0||i>5){
        throw out_of_range("Invalid index");
    }
    switch(i){
        case 0:
            return arrival.toString();
            break;
        case 1:
            return departure.toString();
            break;
        case 2:
            return fromWhere;
            break;
        case 3:
            return destination;
            break;
        case 4:
            return to_string(platformNo);
            break;
        case 5:
            return entryTrain->getName();
            break;

    }





}

const DateAndTime &Entry::getArrival() const {
    return arrival;
}

void Entry::setArrival(const DateAndTime &arrival) {
    Entry::arrival = arrival;
}

const DateAndTime &Entry::getDeparture() const {
    return departure;
}

void Entry::setDeparture(const DateAndTime &departure) {
    Entry::departure = departure;
}

const string &Entry::getFromWhere() const {
    return fromWhere;
}

void Entry::setFromWhere(const string &fromWhere) {
    Entry::fromWhere = fromWhere;
}

const string &Entry::getDestination() const {
    return destination;
}

void Entry::setDestination(const string &destination) {
    Entry::destination = destination;
}

int Entry::getPlatformNo() const {
    return platformNo;
}

void Entry::setPlatformNo(int platformNo) {
    Entry::platformNo = platformNo;
}

Train *Entry::getEntryTrain() {
    return entryTrain;
}
