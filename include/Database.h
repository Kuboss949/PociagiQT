#pragma once
#include <vector>
#include "Entry.h"
#include "validation.h"

using namespace std;

class Database {
    vector<Entry*> data;
    string fileName;
    ifstream reading;
    ofstream writing;
public:
    Database();
    Database(const string &fileName);
    ~Database();

    void loadRecords();
    void saveRecords();
    void setFile(string value);

    void printRecords();
    void createEntry();
    void deleteEntry(int i);
    Entry *getEntryAtIndex(int i);
    string getStringAtIndex(int entryIndex, int strIndex);
    int getDataSize();
    void clear();

};




