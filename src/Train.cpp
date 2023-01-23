#include "Train.h"

/**
 * Base constructor sets name and owner members as empty strings and assign a value of 0.0 to maxVelocity
 */
Train::Train()
{
    name = "";
    owner = "";
    maxVelocity = 0.0;
}
/**
 * This constructor takes all class members and sets owner and maxVelocity in initialization list,
 * name however is set by setter in order to make sure that all it's letters are going to be uppercase
 */
Train::Train(const string &name, const string &owner, const double &maxVelocity):owner(owner),maxVelocity(maxVelocity)
{
    setName(name);
}
/**
 * Copy constructor of Train
 */
Train::Train(const Train &train) {
    this->name=train.name;
    this->owner=train.owner;
    this->maxVelocity=train.maxVelocity;
}

/**
 * name setter takes passed value and make every letter uppercase
 */
void Train::setName(string value)
{
    transform(value.begin(), value.end(), value.begin(), ::toupper);
    this->name = value;
}

/**
 * Name getter, returns the value of name
 */

string Train::getName() const
{
    return this->name;
}

/**
 * Owner setter, sets the value of owner
 */
void Train::setOwner(string value)
{
    this->owner = value;
}

/**
 * Owner getter, returns the value of owner
 */
string Train::getOwner() const
{
    return this->owner;
}

/**
 * maxVelocity setter, sets the value of maxVelocity
 */
void Train::setMaxVelocity(double value)
{
    this->maxVelocity = value;
}

/**
 * maxVelocity getter, returns the value of maxVelocity
 */
double Train::getMaxVelocity() const
{
    return maxVelocity;
}

/**
 * This method writes the value of Train class members into a binary file
 *
 * In order to save strings, it firstly save it's size and then the string
 */
void Train::writeToBinFile(ofstream &stream) {
    if(stream.good()){
        int tmpSize = name.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&name[0], tmpSize);

        tmpSize = owner.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&owner[0], tmpSize);

        stream.write(reinterpret_cast<char*>(&maxVelocity), sizeof(maxVelocity));
    }
}

/**
 * This method reads the value of Train class members from a binary file
 *
 * In order to read strings, it firstly reads it's size and then the resize the member and read it's value from file
 */
void Train::readFromBinFile(ifstream &stream) {
    int tmpSize;
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        name.resize(tmpSize);
        stream.read(&name[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        owner.resize(tmpSize);
        stream.read(&owner[0], tmpSize);

        stream.read(reinterpret_cast<char*>(&maxVelocity), sizeof(maxVelocity));
    }
}




