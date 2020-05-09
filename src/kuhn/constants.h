#ifndef PYKER_CONSTANTS_H
#define PYKER_CONSTANTS_H


#include <string>
#include <array>


typedef std::string InformationSet;
typedef int Card;
typedef std::array<Card, 3> Deck;

// there are two actions, pass and bet
const int NUM_ACTIONS = 2;
const int PASS = 0;  // check or fold
const int BET = 1;  // call or raise


#endif //PYKER_CONSTANTS_H
