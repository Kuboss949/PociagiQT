#include "PassengerTrain.h"

PassengerTrain::PassengerTrain():Train()
{
    maxPassNumber = 0;
    numOfTravelClasses = 0;
    maxPassInClass = nullptr;
}

PassengerTrain::PassengerTrain(string name, string owner, double maxVelocity, int maxPassNumber, int numOfTravelClasses):Train(name, owner, maxVelocity),maxPassNumber(maxPassNumber)
{
    if (numOfTravelClasses > 3 || numOfTravelClasses < 1) {
        throw std::out_of_range("Number of classes must be between 1 and 3!");
    }
    else {
        separatePassengers(numOfTravelClasses);
    }
}

void PassengerTrain::print()
{
    Train::print();
    cout << "Maximum number of Passengers: " << maxPassNumber << endl;
    cout << "Travel Classes: " << numOfTravelClasses << endl;
    for (int i = 0; i < numOfTravelClasses; i++)
        cout << "Number of seats in " << i + 1 << " class: " << maxPassInClass[i] << endl;
}

void PassengerTrain::writeToBinFile(ofstream &stream) {
    Train::writeToBinFile(stream);
    if(stream.good()){
        stream.write(reinterpret_cast<char*>(&maxPassNumber), sizeof(maxPassNumber));
        stream.write(reinterpret_cast<char*>(&numOfTravelClasses), sizeof(numOfTravelClasses));
        stream.write(reinterpret_cast<char*>(maxPassInClass), sizeof(int) * numOfTravelClasses);
    }
}

void PassengerTrain::readFromBinFile(ifstream &stream) {
    Train::readFromBinFile(stream);
    if(stream.good()){
        stream.read(reinterpret_cast<char*>(&maxPassNumber), sizeof(maxPassNumber));
        stream.read(reinterpret_cast<char*>(&numOfTravelClasses), sizeof(numOfTravelClasses));
        if (maxPassInClass== nullptr)
            delete[] maxPassInClass;
        maxPassInClass = new int[numOfTravelClasses];
        stream.read(reinterpret_cast<char*>(maxPassInClass), sizeof(int) * numOfTravelClasses);
    }
}

void PassengerTrain::separatePassengers(int numOfTravelClasses) {
    this->numOfTravelClasses = numOfTravelClasses;
    maxPassInClass = new int[numOfTravelClasses];
    if (numOfTravelClasses == 1)
        maxPassInClass[0] = maxPassNumber;
    else if (numOfTravelClasses == 2) {
        maxPassInClass[0] = maxPassNumber / 3;
        maxPassInClass[1] = maxPassNumber - maxPassInClass[0];
    }else{
        maxPassInClass[0] = maxPassNumber / 6;
        maxPassInClass[1] = (maxPassNumber - maxPassInClass[0])/3;
        maxPassInClass[2] = maxPassNumber - (maxPassInClass[0]+maxPassInClass[1]);
    }
}

void PassengerTrain::setMaxPassNumber(int value) {
    maxPassNumber=value;
    if(maxPassInClass!= nullptr)
        delete [] maxPassInClass;
    separatePassengers(numOfTravelClasses);
}

int PassengerTrain::getMaxPassNumber() {
    return maxPassNumber;
}

void PassengerTrain::setNumOfTravelClasses(int value) {
    if (value > 3 || value < 1) {
        throw std::out_of_range("Number of classes must be between 1 and 3!");
    }
    numOfTravelClasses=value;
    if(maxPassInClass!= nullptr)
        delete [] maxPassInClass;
    separatePassengers(numOfTravelClasses);
}

int PassengerTrain::getNumOfTravelClasses() {
    return numOfTravelClasses;
}

PassengerTrain::~PassengerTrain() {
    delete [] maxPassInClass;
}

PassengerTrain::PassengerTrain(const PassengerTrain &train):Train(train) {
    this->numOfTravelClasses=train.numOfTravelClasses;
    this->maxPassInClass=new int[this->numOfTravelClasses];
    *this->maxPassInClass=*train.maxPassInClass;
}

int PassengerTrain::getNumOfPassAtClass(int index) {
    if(index<0 || index>numOfTravelClasses)
        throw out_of_range("Invalid index, too few travel classes!");
    return maxPassInClass[index];
}

