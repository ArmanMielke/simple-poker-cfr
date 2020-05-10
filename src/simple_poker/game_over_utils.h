#ifndef PYKER_GAME_OVER_UTILS_H
#define PYKER_GAME_OVER_UTILS_H


#include "constants.h"

bool game_over(const History& history);
double calculate_utility(const History& history, Deck cards);


#endif //PYKER_GAME_OVER_UTILS_H
