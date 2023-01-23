#pragma once
#include<iostream>
#include <fstream>
#include <algorithm>

using namespace std;
/**
 * @class Train
 * @brief base train class
 */
class Train
{
protected:
    /**
     * @property name
     * @brief Name (ID) of the train
     */
    string name;
    /**
     * @property owner
     * @brief owner of the train
     */
    string owner;
    /**
     * @property maxVelocity
     * @brief Train's maximum velocity
     */
    double maxVelocity;


public:
    /**
     * @brief Base constructor which sets default values to train members
     */
    Train();
    /**
     * @brief Train constructor with all members
     * @param name train name (ID)
     * @param owner train owner
     * @param maxVelocity train's maximum velocity
     */
    Train(const string &name, const string &owner, const double &maxVelocity);
    /**
     * @brief copy constructor
     * @param train object which we want to copy
     */
    Train(const Train &train);

    /**
     * @brief name setter
     * @param name The new value of name
     */
    void setName(string name);
    /**
     * @brief name getter
     * @return The value of name
     */
    string getName() const;
    /**
     * @brief owner setter
     * @param owner The new value of owner
     */
    void setOwner(string owner);
    /**
     * @brief owner getter
     * @return The value of owner
     */
    string getOwner() const;
    /**
     * @brief maxVelocity setter
     * @param maxVelocity The new value of maxVelocity
     */
    void setMaxVelocity(double maxVelocity);
    /**
     * @brief maxVelocity getter
     * @return The value of maxVelocity
     */
    double getMaxVelocity() const;

    /**
     * @brief Function which writes Train object into binary file
     * @param stream reference to ostream where we want to write our object
     */
    virtual void writeToBinFile(ofstream& stream);
    /**
     * @brief Function which reads Train object into binary file
     * @param stream reference to istream from where we want to read our object
     */
    virtual void readFromBinFile(ifstream& stream);

};

