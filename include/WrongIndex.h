#ifndef UNTITLED5_WRONGINDEX_H
#define UNTITLED5_WRONGINDEX_H
#include <exception>
#include <iostream>
using namespace std;
/**
 * @class WrongIndex
 * @brief Exception class that inherits from std::exception
 */
class WrongIndex:public exception {
    /**
     * @property msg
     * @brief message for user
     */
    string msg;
public:
    /**
     * @brief Constructor of WrongIndex class
     * @param message Message to user
     */
    WrongIndex(string message);

    /**
     * @brief what() exception function
     * @return msg pointer
     */
    string what();
};


#endif //UNTITLED5_WRONGINDEX_H
