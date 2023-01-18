#include "CargoTrain.h"


CargoTrain::CargoTrain():Train() {
    cargoType="";
    maxCargoMass=0.0;
}

CargoTrain::CargoTrain(string name, string owner, double maxVelocity, string cargoType, double maxCargoMass):Train(name, owner, maxVelocity),cargoType(cargoType),maxCargoMass(maxCargoMass)
{
}

void CargoTrain::print() {
    Train::print();
    cout << "Cargo Type: " << cargoType << endl;
    cout << "Max cargo mass: " << maxCargoMass << " t" << endl;
}

void CargoTrain::setCargoType(string value) {
    cargoType=value;
}

string CargoTrain::getCargoType() {
    return cargoType;
}

void CargoTrain::setMaxCargoMass(double value) {
    maxCargoMass=value;
}

double CargoTrain::getMaxCargoMass() {
    return maxCargoMass;
}

void CargoTrain::writeToBinFile(ofstream &stream) {
    Train::writeToBinFile(stream);
    if(stream.good()){
        int tmpSize = this->cargoType.size();
        stream.write(reinterpret_cast<char*>(&tmpSize), sizeof(int));
        stream.write(&cargoType[0], tmpSize);
        stream.write(reinterpret_cast<char*>(&maxCargoMass), sizeof(maxCargoMass));
    }
}

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

CargoTrain::CargoTrain(const CargoTrain &train):Train(train) {
    this->cargoType=train.cargoType;
    this->maxCargoMass=train.maxCargoMass;
}


