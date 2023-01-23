#include "PassengerTrain.h"
/**
 * Base constructor assigns 0 to maxPassNumber and numOfTravelClasses. It also mark maxPassInClass as nullptr
 */
PassengerTrain::PassengerTrain():Train()
{
    maxPassNumber = 0;
    numOfTravelClasses = 0;
    maxPassInClass = nullptr;
}
/**
 * This constructor assigns a value to every provided member in initialization list.
 * It also throws out_of range exception if numOfTravelClasses isn't between 1 and 3, otherwise it call separatePassengers() method
 */
PassengerTrain::PassengerTrain(string name, string owner, double maxVelocity, int maxPassNumber, int numOfTravelClasses):Train(name, owner, maxVelocity),maxPassNumber(maxPassNumber), numOfTravelClasses(numOfTravelClasses)
{
    if (numOfTravelClasses > 3 || numOfTravelClasses < 1) {
        throw out_of_range("Number of classes must be between 1 and 3!");
    }
    else {
        separatePassengers();
    }
}

/**
 * This function separate passengers/seats between travel classes.
 * If there is one class all seats are in it
 * For 2 classes in 1st class there is 1/3 of seats
 * For 3 classes in 1st class we have 1/6 of all seats, in 2nd - 1/3 of the rest
 */
void PassengerTrain::separatePassengers() {
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
/**
 * Copy constructor of PassengerTrain - firstly it runs base copy constructor
 */
PassengerTrain::PassengerTrain(const PassengerTrain &train):Train(train) {
    this->maxPassNumber=train.maxPassNumber;
    this->numOfTravelClasses=train.numOfTravelClasses;
    this->maxPassInClass=new int[this->numOfTravelClasses];
    *this->maxPassInClass=*train.maxPassInClass;
}

/**
 * Deconstructor deletes maxPassInClass array
 */
PassengerTrain::~PassengerTrain() {
    delete [] maxPassInClass;
}

/**
 * Setter for maxPassNumber needs to run separatePassengers() function after assigning new value
 */

void PassengerTrain::setMaxPassNumber(int value) {
    maxPassNumber=value;
    if(maxPassInClass!= nullptr)
        delete [] maxPassInClass;
    separatePassengers();
}

/**
 * maxPassNumber getter
 */
int PassengerTrain::getMaxPassNumber() const {
    return maxPassNumber;
}

/**
 * numOfTravelClasses setter throws out_of_range exception if value isn't between 1 and 3
 * It also needs to run separatePassengers() function after assigning new value
 */
void PassengerTrain::setNumOfTravelClasses(int value) {
    if (value > 3 || value < 1) {
        throw std::out_of_range("Number of classes must be between 1 and 3!");
    }
    numOfTravelClasses=value;
    if(maxPassInClass!= nullptr)
        delete [] maxPassInClass;
    separatePassengers();
}

/**
 * numOfTravelClasses getter
 */
int PassengerTrain::getNumOfTravelClasses() const {
    return numOfTravelClasses;
}

/**
 * This method returns the number of seats in index+1 class
 */
int PassengerTrain::getNumOfPassAtClass(int index) {
    if(index<0 || index>=numOfTravelClasses)
        throw out_of_range("Invalid index, too few travel classes!");
    return maxPassInClass[index];
}
/**
 * This method writes the value of PassengerTrain class members into a binary file
 *
 * In order to save strings, it firstly save it's size and then the string
 */
void PassengerTrain::writeToBinFile(ofstream &stream) {
    Train::writeToBinFile(stream);
    if(stream.good()){
        stream.write(reinterpret_cast<char*>(&maxPassNumber), sizeof(maxPassNumber));
        stream.write(reinterpret_cast<char*>(&numOfTravelClasses), sizeof(numOfTravelClasses));
        stream.write(reinterpret_cast<char*>(maxPassInClass), sizeof(int) * numOfTravelClasses);
    }
}

/**
 * This method reads the value of PassengerTrain class members from a binary file
 *
 * In order to read strings, it firstly reads it's size and then the resize the member and read it's value from file
 */
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