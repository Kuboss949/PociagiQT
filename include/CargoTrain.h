#pragma once
#include "Train.h"
#include<vector>

class CargoTrain : public Train
{
    string cargoType;
    double maxCargoMass;
public:
    CargoTrain();

    CargoTrain(string name, string owner, double maxVelocity, string cargoType, double maxCargoMass);
    CargoTrain(const CargoTrain &train);

    void print() override;


    void setCargoType(string value);
    string getCargoType();
    void setMaxCargoMass(double value);
    double getMaxCargoMass();

    void writeToBinFile(ofstream& stream) override;
    void readFromBinFile(ifstream& stream) override;

};

