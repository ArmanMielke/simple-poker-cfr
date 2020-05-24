#ifndef SIMPLE_POKER_CFR_PLAYER_H
#define SIMPLE_POKER_CFR_PLAYER_H


#include "information_set.h"
#include "action.h"


/// Abstract base class for objects that control the behaviour of a player for simplified poker.
class Player {
public:
    [[nodiscard]] virtual Action do_betting_action(InformationSet info_set) = 0;
};


#endif //SIMPLE_POKER_CFR_PLAYER_H
