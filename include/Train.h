#pragma once
#include<iostream>
#include <fstream>

using namespace std;

class Train
{
protected:
    string name;
    string owner;
    double maxVelocity;


public:

    Train();

    Train(string name, string owner, double maxVelocity);
    Train(const Train &train);

    virtual void print();

    void setName(string name);
    string getName();
    void setOwner(string owner);
    string getOwner();
    void setMaxVelocity(double maxVelocity);
    double getMaxVelocity();



    virtual void writeToBinFile(ofstream& stream);
    virtual void readFromBinFile(ifstream& stream);

};

