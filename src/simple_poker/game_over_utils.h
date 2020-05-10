#ifndef PYKER_GAME_OVER_UTILS_H
#define PYKER_GAME_OVER_UTILS_H


#include "constants.h"

bool game_over(const std::string& history);
double calculate_utility(const std::string& history, Deck cards);


#endif //PYKER_GAME_OVER_UTILS_H
