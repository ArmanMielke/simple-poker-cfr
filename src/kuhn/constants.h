#ifndef PYKER_CONSTANTS_H
#define PYKER_CONSTANTS_H


#include <string>
#include <array>


// The betting round works like this:
//
// |       Sequential Actions       |            Payoff             |
// |----------+----------+----------|-------------------------------|
// | Player 1 | Player 2 | Player 1 |                               |
// |----------|----------|----------|-------------------------------|
// | pass     | pass     |          | +1 to player with higher card |
// | pass     | bet      | pass     | +1 to player 2                |
// | pass     | bet      | bet      | +2 to player with higher card |
// | bet      | pass     |          | +1 to player 1                |
// | bet      | bet      |          | +2 to player with higher card |


typedef std::string InformationSet;
typedef int Card;
typedef std::array<Card, 3> Deck;

// there are two actions, pass and bet
const int NUM_ACTIONS = 2;
const int PASS = 0;  // check or fold
const int BET = 1;  // call or raise


#endif //PYKER_CONSTANTS_H
