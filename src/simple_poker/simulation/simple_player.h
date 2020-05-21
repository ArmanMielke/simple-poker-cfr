#ifndef PYKER_SIMPLE_PLAYER_H
#define PYKER_SIMPLE_PLAYER_H


#include "simple_poker/information_set.h"
#include "simple_poker/action.h"


/// Abstract base class for objects that control the behaviour of a player for simplified poker.
class SimplePlayer {
public:
    [[nodiscard]] virtual Action do_betting_action(InformationSet info_set) = 0;
};


#endif //PYKER_SIMPLE_PLAYER_H
