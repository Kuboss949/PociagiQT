#include "CargoTrain.h"

/**
 * Base constructor assigns 0.0 to maxCargoMass and an empty string to cargoType
 */
CargoTrain::CargoTrain():Train() {
    cargoType="";
    maxCargoMass=0.0;
}
/**
 * This constructor assigns a value to every provided member in initialization list.
 */
CargoTrain::CargoTrain(const string &name, const string &owner, const double &maxVelocity, const string &cargoType, const double &maxCargoMass):Train(name, owner, maxVelocity),cargoType(cargoType),maxCargoMass(maxCargoMass)
{
}

/**
 * cargoType setter
 */
void CargoTrain::setCargoType(string value) {
    cargoType=value;
}

/**
 * cargoType getter
 */
string CargoTrain::getCargoType() {
    return cargoType;
}
/**
 * maxCargoMass setter
 */
void CargoTrain::setMaxCargoMass(double value) {
    maxCargoMass=value;
}

/**
 * maxCargoMass getter
 */
double CargoTrain::getMaxCargoMass() const {
    return maxCargoMass;
}

/**
 * This method writes the value of CargoTrain class members into a binary file
 *
 * In order to save strings, it firstly save it's size and then the string
 */
void CargoTrain::writeToBinFile(ofstream &stream) {
    Train::writeToBinFile(stream);
    if(stream.good()){
        int tmpSize = this->cargoType.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&cargoType[0], tmpSize);
        stream.write(reinterpret_cast<char*>(&maxCargoMass), sizeof(maxCargoMass));
    }
}

/**
 * This method reads the value of CargoTrain class members from a binary file
 *
 * In order to read strings, it firstly reads it's size and then the resize the member and read it's value from file
 */
void CargoTrain::readFromBinFile(ifstream &stream) {
    Train::readFromBinFile(stream);
    int tmpSize;
    if(stream.good()){
    stream.read(reinterpret_cast<char*>(&tmpSize), sizeof(int));
    cargoType.resize(tmpSize);
    stream.read(&cargoType[0], tmpSize);
    stream.read(reinterpret_cast<char*>(&maxCargoMass), sizeof(maxCargoMass));
    }
}


