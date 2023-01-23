#pragma once
#include "DateAndTime.h"
#include "Train.h"
#include "CargoTrain.h"
#include "PassengerTrain.h"
#include <iomanip>

using namespace std;
/**
 * @class Entry
 * @brief This class contains information about train departure, destination etc.
 */
class Entry {
    /**
     * @property arrival
     * @brief Arrival time of train
     */
    DateAndTime arrival;
    /**
     * @property departure
     * @brief Departure time of train
     */
    DateAndTime departure;
    /**
     * @property destination
     * @brief Destination time of train
     */
    string destination;
    /**
     * @property fromWhere
     * @brief Train's point of departure
     */
    string fromWhere;
    /**
     * @property platformNo
     * @brief Number of platform where train will arrive
     */
    int platformNo;
    /**
     * @property entryTrain
     * @brief pointer to train object
     */
    Train *entryTrain;
public:
    /**
     * @brief Base constructor, which sets default values to members
     */
    Entry();

    /**
     * @brief Constructor with all members
     * @param arrival Arrival time
     * @param departure Departure time
     * @param fromWhere Train's point of departure (origin)
     * @param destination Train's destination
     * @param platformNo Platform number
     * @param entryTrain Pointer to Train object
     */
    Entry(const DateAndTime &arrival, const DateAndTime &departure, const string &fromWhere, const string &destination,
          int platformNo, Train *entryTrain);

    /**
     * @brief Entry copy constructor
     * @param entry object that we want to copy
     */
    Entry(const Entry &entry);

    /**
     * @brief Entry deconstructor
     */
    ~Entry();
    /**
     * @brief [] Entry operator
     * @param i number of position in Entry
     * @return string representation of i element of Entry
     */
    string operator[](int i);

    /**
     * @brief arrival getter
     * @return The value of arrival
     */
    DateAndTime getArrival() const;
    /**
     * @brief arrival setter
     * @param value The new value of arrival
     */
    void setArrival(const DateAndTime &value);
    /**
     * @brief departure getter
     * @return The value of departure
     */
    DateAndTime getDeparture() const;
    /**
     * @brief departure setter
     * @param value The new value of departure
     */
    void setDeparture(const DateAndTime &value);

    /**
     * @brief fromWhere getter
     * @return The value of fromWhere
     */
    string getFromWhere() const;

    /**
     * @brief fromWhere setter
     * @param value The new value of fromWhere
     */
    void setFromWhere(const string &value);

    /**
     * @brief destination getter
     * @return The value of destination
     */
    string getDestination() const;

    /**
     * @brief destination setter
     * @param value The new value of destination
     */
    void setDestination(const string &value);

    /**
     * @brief platformNo getter
     * @return The value of platformNo
     */
    int getPlatformNo() const;

    /**
     * @brief platformNo setter
     * @param value The new value of platformNo
     */
    void setPlatformNo(int platformNo);

    /**
     * @brief entryTrain getter
     * @return Pointer to entryTrain
     */
    Train* getEntryTrain();

    /**
     * @brief entryTrain setter
     * @param value New pointer to entryTrain
     */
    void setEntryTrain(Train* value);

    /**
     * @brief Function which writes Entry object into binary file
     * @param stream reference to ostream where we want to write our object
     */
    void writeToBinFile(ofstream &stream);

    /**
     * @brief Function which reads Entry object into binary file
     * @param stream reference to istream from where we want to read our object
     */
    void readFromBinFile(ifstream &stream);

};