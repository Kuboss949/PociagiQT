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
    Entry* tmp = new Entry();
    data.push_back(tmp);
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
