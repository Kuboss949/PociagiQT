#include "Entry.h"


/**
 * This constructor runs base DateAndTime constructor for arrival and departure members
 * It also assigns empty strings to destination and fromWhere members
 * It assigns 0 to platformNo and nullptr to entryTrain
 */
Entry::Entry() {
    arrival=DateAndTime();
    departure=DateAndTime();
    destination="";
    fromWhere="";
    platformNo=0;
    entryTrain=nullptr;
}
/**
 * This constructor sets every member of Entry in initialization list
 */
Entry::Entry(const DateAndTime &arrival, const DateAndTime &departure, const string &fromWhere,
             const string &destination, int platformNo, Train *entryTrain) : arrival(arrival), departure(departure),
                                                                        fromWhere(fromWhere), destination(destination),
                                                                        platformNo(platformNo), entryTrain(entryTrain) {}

/**
 * Entry copy constructor
 */
Entry::Entry(const Entry &entry) {
    this->arrival=entry.arrival;
    this->departure=entry.departure;
    this->fromWhere=entry.fromWhere;
    this->destination=entry.destination;
    this->platformNo=entry.platformNo;
    if (dynamic_cast<CargoTrain*>(entry.entryTrain)!= nullptr) {
        this->entryTrain = new CargoTrain();
    } else if (dynamic_cast<PassengerTrain*>(entry.entryTrain)!= nullptr) {
        this->entryTrain = new PassengerTrain();
    } else {
        this->entryTrain= new Train();
    }

    *this->entryTrain=*entry.entryTrain;
}
/**
 * Entry deconstructor in which we delete entryTrain
 */
Entry::~Entry() {
    delete entryTrain;
}

/**
 * [] operator which use switch case to choose which field we want to get as string
 */
string Entry::operator[](int i) {
    switch(i){
        case 0:
            return arrival.toString();
        case 1:
            return departure.toString();
        case 2:
            return destination;
        case 3:
            return fromWhere;
        case 4:
            return to_string(platformNo);
        case 5:
            return entryTrain->getName();
        default:
            throw out_of_range("Invalid index");
    }
}

/**
 * arrival getter
 */
DateAndTime Entry::getArrival() const {
    return arrival;
}
/**
 * arrival setter
 */
void Entry::setArrival(const DateAndTime &value) {
    arrival = value;
}

/**
 * departure getter
 */
DateAndTime Entry::getDeparture() const {
    return departure;
}

/**
 * departure setter
 */
void Entry::setDeparture(const DateAndTime &value) {
    departure = value;
}

/**
 * fromWhere getter
 */
string Entry::getFromWhere() const {
    return fromWhere;
}

/**
 * fromWhere setter
 */
void Entry::setFromWhere(const string &value) {
    fromWhere = value;
}

/**
 * destination getter
 */
string Entry::getDestination() const {
    return destination;
}

/**
 * destination setter
 */
void Entry::setDestination(const string &value) {
    destination = value;
}
/**
 * platformNo getter
 */
int Entry::getPlatformNo() const {
    return platformNo;
}

/**
 * platformNo setter
 */
void Entry::setPlatformNo(int value) {
    platformNo = value;
}

/**
 * entryTrain getter
 */
Train *Entry::getEntryTrain() {
    return entryTrain;
}
/**
 * entryTrain setter - after assigning new value program deletes old object
 */
void Entry::setEntryTrain(Train *value) {
    Train *old=entryTrain;
    entryTrain=value;
    delete old;
}


/**
 * This method writes the value of Entry class members into a binary file
 *
 * In order to save strings, it firstly save it's size and then the string
 *
 * It uses member function writeToBinFile methods
 *
 * Before writing entryTrain to file program writes to file a number which define it's class. To define it it uses dynamic_cast
 */
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
    if (dynamic_cast<CargoTrain*>(entryTrain)!= nullptr) {
        type=2;
    } else if (dynamic_cast<PassengerTrain*>(entryTrain)!= nullptr) {
        type=1;
    } else {
        type=0;
    }
    stream.write(reinterpret_cast<char*>(&type), sizeof(int));
    entryTrain->writeToBinFile(stream);
}

/**
 * This method reads the value of Entry class members from a binary file
 *
 * In order to read strings, it firstly reads it's size and then the resize the member and read it's value from file
 *
 * Before reading entryTrain we need to define it's class (Train, PassengerTrain or CargoTrain)
 */
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
