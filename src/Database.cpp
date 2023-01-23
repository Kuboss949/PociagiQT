//
// Created by creaz on 12.01.2023.
//

#include "Database.h"

/**
 * Base Database constructor assigns an empty string to fileName and reserve 200 places in vector
 */
Database::Database() {
    fileName="";
    data.reserve(200);
}

/**
 * This method loads records to data vector. If file doesn't exist or there is problem with opening it, method returns false
 */
bool Database::loadRecords() {
    reading.open(fileName);
    if(!reading.good()){
        return false;
    }
    while(!reading.eof()){
        auto* tmp = new Entry;
        tmp->readFromBinFile(reading);
        if(tmp->getFromWhere()=="" && tmp->getDestination()==""){
            delete tmp;
            break;
        }
        data.push_back(tmp);
    }
    reading.close();
    return true;
}

/**
 * This function creates entry and assigns to it a CargoTrain object created with base constructor. Then it adds it to vector
 */
void Database::createEntry() {
    auto* tmp = new Entry();
    Train* train = new CargoTrain();
    tmp->setEntryTrain(train);
    data.push_back(tmp);
}

/**
 * This function saves data vector values into a binary file
 */
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

/**
 * fileName setter
 */
void Database::setFile(const string &value) {
    fileName=value;
}

/**
 * This function returns pointer to Entry at i index, if index is invalid, it throws out_of_range exception
 */
Entry *Database::getEntryAtIndex(int i) {
    if(i<0 || i>data.size()){
        throw out_of_range("Invalid index");
    }
    return data[i];
}

/**
 * Method that returns size of data vector
 */
int Database::getDataSize() {
    return data.size();
}

/**
 * Clears whole data vector by deleting all entries and then using clear() method
 */
void Database::clear() {
    for (auto i = data.begin(); i != data.end(); ++i) {
        delete *i;
    }
    data.clear();
}

/**
 * Database deconstructor
 */
Database::~Database() {
    for (auto ptr : data) {
        delete ptr;
    }
}

/**
 * Method that deletes entry at i index, if index is invalid it throws out_of_range exception
 */
void Database::deleteEntry(int i) {
    if(i<0 || i>data.size() || data.size()==0){
        throw out_of_range("Invalid index");
    }
    delete data[i];
    data.erase(data.begin()+i);
}

/**
 * This method gets string at j index from Entry at i index of data vector
 * It use Entry [] operator
 */
string Database::getStringAtIndex(int i, int j) {
    if(i<0 || i>=data.size() || j<0 || j>5){
        throw out_of_range("Invalid index!");
    }
    return data[i][0][j];
}

/**
 * This method gets string at str index from Entry at i index of data vector
 *
 * It use Entry [] operator, for various string function returns string at different Entry indexes
 *
 * If i is invalid method throws out_of_range exception, if str is invalid it throws invalid_argument exception
 */
string Database::getStringAtIndex(int i, const string &str) {
    if(i<0 || i>=data.size()){
        throw out_of_range("Invalid index!");
    }
    if(str=="Arrival"){
        return data[i][0][0];
    }else if(str=="Departure"){
        return data[i][0][1];
    }else if(str=="Destination"){
        return data[i][0][2];
    }else if(str=="Point of departure"){
        return data[i][0][3];
    }else if(str=="Platform Number"){
        return data[i][0][4];
    }else if(str=="Train name"){
        return data[i][0][5];
    }else{
        throw invalid_argument("Invalid string!");
    }
}
