#pragma once
#include "Train.h"
class PassengerTrain : public Train
{
    int maxPassNumber;
    int numOfTravelClasses;
    int* maxPassInClass;
public:
    PassengerTrain();

    PassengerTrain(string name, string owner, double maxVelocity, int maxPassNumber, int numOfTravelClasses);

    PassengerTrain(const PassengerTrain &train);

    ~PassengerTrain();

    void separatePassengers(int numOfTravelClasses);

    void setMaxPassNumber(int value);
    int getMaxPassNumber();
    void setNumOfTravelClasses(int value);
    int getNumOfTravelClasses();


    void print() override;
    void writeToBinFile(ofstream& stream) override;
    void readFromBinFile(ifstream& stream) override;


};

