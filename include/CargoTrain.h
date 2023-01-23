#pragma once
#include "Train.h"
#include<vector>

/**
 * @class CargoTrain
 * @brief CargoTrain class that inherits from Train class
 */
class CargoTrain : public Train
{
    /**
     * @property cargoType
     * @brief Name of train's cargo type
     */
    string cargoType;
    /**
     * @property maxCargoMass
     * @brief Maximum mass of cargo carried by train in tons
     */
    double maxCargoMass;
public:
    /**
     * @brief Base constructor which sets default values to CargoTrain members
     */
    CargoTrain();

    /**
     * @brief Constructor with all class members
     * @param name Train's name
     * @param owner Train's owner
     * @param maxVelocity Train's maximum velocity
     * @param cargoType Train's cargo type
     * @param maxCargoMass Train's maximum cargo mass in tons
     */
    CargoTrain(const string &name, const string &owner, const double &maxVelocity, const string &cargoType, const double &maxCargoMass);

    /**
     * @brief cargoType setter
     * @param name The new value of cargoType
     */
    void setCargoType(string value);
    /**
     * @brief cargoType getter
     * @return The value of cargoType
     */
    string getCargoType();
    /**
     * @brief maxCargoMass setter
     * @param name The new value of maxCargoMass
     */
    void setMaxCargoMass(double value);
    /**
     * @brief maxCargoMass getter
     * @return The value of maxCargoMass
     */
    double getMaxCargoMass() const;
    /**
     * @brief Function which writes CargoTrain object into binary file
     * @param stream reference to ostream where we want to write our object
     */
    void writeToBinFile(ofstream& stream) override;
    /**
     * @brief Function which reads CargoTrain object into binary file
     * @param stream reference to istream from where we want to read our object
     */
    void readFromBinFile(ifstream& stream) override;

};

