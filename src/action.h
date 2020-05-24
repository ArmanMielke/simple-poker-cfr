#ifndef SIMPLE_POKER_CFR_ACTION_H
#define SIMPLE_POKER_CFR_ACTION_H


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


#endif //SIMPLE_POKER_CFR_ACTION_H
