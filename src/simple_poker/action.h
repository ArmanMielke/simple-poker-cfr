#ifndef PYKER_ACTION_H
#define PYKER_ACTION_H


#include <string>
#include <vector>


const int NUM_ACTIONS = 2;
enum Action: uint8_t {
    /// check or fold
    PASS = 0,
    /// call or raise
    BET = 1,
};

typedef std::vector<Action> History;


#endif //PYKER_ACTION_H
