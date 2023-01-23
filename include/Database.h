#pragma once
#include <vector>
#include "Entry.h"
#include "validation.h"

using namespace std;

/**
 * @class Database
 * @brief This class manages the vector of entries and helps with managing it
 */
class Database {
    /**
     * @property data
     * @brief The vector of Entry pointers
     */
    vector<Entry*> data;
    /**
     * @property filename
     * @brief The name of file where we want to write/from where we want to read
     */
    string fileName;
    /**
     * @property reading
     * @brief reading stream
     */
    ifstream reading;
    /**
     * @property writing
     * @brief writing stream
     */
    ofstream writing;
public:
    /**
     * @brief Base constructor of Database class
     */
    Database();
    /**
     * @brief Deconstructor of Database class
     */
    ~Database();
    /**
     * @brief fileName setter
     * @param value The new value of fileName
     */
    void setFile(const string &value);

    /**
     * @brief Method which reads Entries from file into data vector
     * @return returns true if reading succeed
     */
    bool loadRecords();
    /**
     * @brief Method which writes Entries from data vector into a file
     */
    void saveRecords();

    /**
     * @brief This method creates new entry and adds it to data vector
     */
    void createEntry();

    /**
     * @brief This method deletes entry at i index from data vector
     * @param i index of Entry
     */
    void deleteEntry(int i);

    /**
     * @brief Method that returns pointer to Entry at i index of data vector
     * @param i index of Entry
     * @return pointer to Entry at i index
     */
    Entry *getEntryAtIndex(int i);

    /**
     * @brief This method is used to get size of data vector
     * @return Size of data vector
     */
    int getDataSize();

    /**
     * @brief Method that clears data vector
     */
    void clear();

    /**
     * @brief This method is used to get a string at j index (number) from Entry at i index of data vector
     * @param i index of Entry
     * @param j index of String (number)
     * @return String at j index (number) from Entry at i index
     */
    string getStringAtIndex(int i, int j);

    /**
     * @brief This method is used to get a string at j index (text) from Entry at i index of data vector
     * @param i index of Entry
     * @param str index of String (text)
     * @return String at j index (text) from Entry at i index
     */
    string getStringAtIndex(int i, const string &str);

};




