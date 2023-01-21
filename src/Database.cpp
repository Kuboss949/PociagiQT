//
// Created by creaz on 12.01.2023.
//

#include "Database.h"




Database::Database() {
    fileName="";
}

Database::Database(const string &fileName):fileName(fileName) {

}


bool Database::loadRecords() {
    reading.open(fileName);
    if(!reading.good()){
        return false;
    }
    while(!reading.eof()){
        auto* tmp = new Entry;
        tmp->readFromBinFile(reading);
        if(tmp->getFromWhere()==""){
            delete tmp;
            break;
        }
        data.push_back(tmp);
    }
    reading.close();
    return true;
}

void Database::createEntry() {
    auto* tmp = new Entry();
    data.push_back(tmp);
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


int Database::getDataSize() {
    return data.size();
}

void Database::clear() {
    for (auto i = data.begin(); i != data.end(); ++i) {
        delete *i;
    }
    data.clear();
}

Database::~Database() {
    for (auto ptr : data) {
        delete ptr;
    }
}

void Database::deleteEntry(int i) {
    if(i<0 || i>data.size() || data.size()==0){
        throw out_of_range("Invalid index");
    }
    delete data[i];
    data.erase(data.begin()+i);
}
