#include "WrongIndex.h"
/**
 * WrongIndex constructor
 */
WrongIndex::WrongIndex(string message):msg(message) {
}
/**
 * what() exception function
 */
string WrongIndex::what() {
    return msg;
}

