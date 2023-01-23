#pragma once
#include "Train.h"
/**
 * @class PassengerTrain
 * @brief PassengerTrain class that inherits from Train class
 */
class PassengerTrain : public Train
{
    /**
     * @property maxPassNumber
     * @brief Train's maximum capacity; number of seats
     */
    int maxPassNumber;
    /**
     * @property numOfTravelClasses
     * @brief Number of train's travel classes
     */
    int numOfTravelClasses;
    /**
     * @property maxPassInClass
     * @brief pointer to array that stores maximum number of seats in each class
     */
    int* maxPassInClass;
public:
    /**
     * @brief Base constructor which sets default values to PassengerTrain members
     */
    PassengerTrain();

    /**
     * @brief Constructor with all class members except maxPassInClass pointer
     * @param name Train's name
     * @param owner Train's owner
     * @param maxVelocity Train's maximum velocity
     * @param maxPassNumber Train's maximum passenger capacity
     * @param numOfTravelClasses Train's number of travel classes
     */
    PassengerTrain(string name, string owner, double maxVelocity, int maxPassNumber, int numOfTravelClasses);
    /**
     * @brief Copy constructor of PassengerTrain
     * @param train object which we want to copy
     */
    PassengerTrain(const PassengerTrain &train);
    /**
     * @brief deconstructor of PassengerTrain
     */
    ~PassengerTrain();

    /**
     * @brief function which sets the maximum number of passengers in each class
     */
    void separatePassengers();

    /**
     * @brief maxPassNumber setter
     * @param name The new value of maxPassNumber
     */
    void setMaxPassNumber(int value);
    /**
     * @brief maxPassNumber getter
     * @return The value of maxPassNumber
     */
    int getMaxPassNumber() const;
    /**
     * @brief numOfTravelClasses setter
     * @param name The new value of numOfTravelClasses
     */
    void setNumOfTravelClasses(int value);
    /**
     * @brief numOfTravelClasses getter
     * @return The value of numOfTravelClasses
     */
    int getNumOfTravelClasses() const;
    /**
     * @brief gets maximum number of passengers at i+1 class
     * @param i number of class
     * @return The maximum number of passengers at i+1 class
     */
    int getNumOfPassAtClass(int index);

    /**
     * @brief Function which writes PassengerTrain object into binary file
     * @param stream reference to ostream where we want to write our object
     */
    void writeToBinFile(ofstream& stream) override;
    /**
     * @brief Function which reads PassengerTrain object into binary file
     * @param stream reference to istream from where we want to read our object
     */
    void readFromBinFile(ifstream& stream) override;


};

