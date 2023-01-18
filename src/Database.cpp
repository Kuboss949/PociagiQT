//
// Created by creaz on 12.01.2023.
//

#include "Database.h"

template <typename T>
void enterAndValidate(T &value){
    do{
        cin >> value;
        if(value<0){
            cout << "Entered invalid data, try again" << endl;
        }
    }while(value<0);
}


Database::Database() {
    fileName="";
}

Database::Database(const string &fileName):fileName(fileName) {

}


void Database::loadRecords() {
    reading.open(fileName);
    if(!reading.good()){
        cout << "Problem with file access!" << endl;
        return;
    }
    while(!reading.eof()){
        Entry* tmp = new Entry;
        tmp->readFromBinFile(reading);
        if(tmp->getFromWhere()==""){
            delete tmp;
            break;
        }
        data.push_back(tmp);
    }
    reading.close();
}

void Database::createEntry() {
    string tmp, fromWhere, destination, trainName, trainOwner;
    DateAndTime arrival, departure;
    Train *entryTrain;
    Entry *entry;
    int platformNo, trainType;
    bool validResult;
    double maxVelocity;


    do {
        cout << "Please enter arrival date in DD-MM-YYYY format: " << endl;
        cin >> tmp;
        if(!(validResult=validateDate(tmp, arrival)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);

    do {
        cout << "Please enter arrival time in HH:MM 24H format: " << endl;
        cin >> tmp;
        if(!(validResult=validateHour(tmp, arrival)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);

    do {
        cout << "Please enter departure date in DD-MM-YYYY format (if it's the same as arrival, press enter): " << endl;
        cin.ignore();
        getline(cin, tmp);
        if(!(validResult=(validateDate(tmp, departure) || tmp.length()==0)) )
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);
    if(tmp.length()==0){
        departure=arrival;
    }

    do {
        cout << "Please enter departure time in HH:MM 24H format: " << endl;
        cin >> tmp;
        if(!(validResult=validateHour(tmp, departure)))
            cout << "Data entered in wrong format, try again:" << endl;
    }while(!validResult);


    cout << "Enter train destination: "<< endl;
    cin.ignore();
    getline(cin, destination);
    cout << "Enter train point of departure: "<< endl;
    getline(cin, fromWhere);

    cout << "Enter platform number: " << endl;
    enterAndValidate(platformNo);


    cout << "Enter train type: " << endl << "1) Passenger Train" << endl << "2) Cargo Train" << endl;

    do{
        cin >> trainType;
        if(trainType!=1 && trainType!=2){
            cout << "Entered invalid option, try again" << endl;
        }
    }while(trainType!=1 && trainType!=2);



    cout << "Enter train name: "<< endl;
    cin >> trainName;
    cout << "Enter train owner: "<< endl;
    cin.ignore();
    getline(cin, trainOwner);

    cout << "Enter train max velocity: "<< endl;
    enterAndValidate(maxVelocity);


    if(trainType==1){
        int PassNumber;
        int numOfTravelClasses;
        cout << "Enter the maximum number of passengers: "<< endl;
        enterAndValidate(PassNumber);

        cout << "Enter number of travel classes (max 3): "<< endl;
        do{
            cin >> numOfTravelClasses;
            if(numOfTravelClasses<0 || numOfTravelClasses>3){
                cout << "Entered invalid option, try again" << endl;
            }
        }while(numOfTravelClasses<0 || numOfTravelClasses>3);
        entryTrain = new PassengerTrain(trainName, trainOwner, maxVelocity, PassNumber, numOfTravelClasses);
    }else{
        string trainCargoType;
        int trainMaxCargoMass;

        cout << "Enter train cargo type: "<< endl;
        cin >> trainCargoType;

        cout << "Enter train maximum cargo mass in tons: "<< endl;
        enterAndValidate(trainMaxCargoMass);

        entryTrain=new CargoTrain(trainName, trainOwner, maxVelocity, trainCargoType, trainMaxCargoMass);
    }
    entry=new Entry(arrival, departure, fromWhere, destination, platformNo, entryTrain);
    data.push_back(entry);
}

void Database::printRecords() {

    //cout << "ARRIVAL TIME" << "\t" << "DEPARTURE TIME" << "\t" << "DESTINATION" << "\t" << "ORIGIN" << "\t" << "PLATFORM NO" << "\t" << "TRAIN ID" << endl;

    for(int i=0;i<data.size();i++)
        cout << *data[i];

}

void Database::saveRecords() {
    writing.open(fileName);
    if(!writing.good()){
        cout << "Opening file error! \n";
        return;
    }

    for(int i=0;i<data.size();i++){
        data[i]->writeToBinFile(writing);
    }
    writing.close();
}

void Database::setFile(string value) {
    fileName=value;
}

Entry *Database::getEntryAtIndex(int i) {
    if(i<0 || i>data.size()){
        throw out_of_range("Invalid index");
    }
    return data[i];
}

string Database::getStringAtIndex(int entryIndex, int strIndex) {
    if(entryIndex<0 || entryIndex>=data.size() || strIndex<0 || strIndex>5){
        throw out_of_range("Invalid index!");
    }
    return data[entryIndex][0][strIndex];
}

int Database::getDataSize() {
    return data.size();
}

void Database::clear() {
    for (auto i = data.begin(); i != data.end(); ++i) {
        delete *i;
    }
    data.clear();
}
