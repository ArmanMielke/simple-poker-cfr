#ifndef SIMPLE_POKER_CFR_GAME_OVER_UTILS_H
#define SIMPLE_POKER_CFR_GAME_OVER_UTILS_H


#include "action.h"
#include "deck.h"


bool game_over(const History& history);
/// @return utility for the starting player.
double calculate_utility(const History& history, const Deck& cards);


#endif //SIMPLE_POKER_CFR_GAME_OVER_UTILS_H
