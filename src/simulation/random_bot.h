#ifndef SIMPLE_POKER_CFR_RANDOM_BOT_H
#define SIMPLE_POKER_CFR_RANDOM_BOT_H


#include "player.h"

#include <random>


/// A simplified poker player that always chooses its actions uniformly at random.
class RandomBot : public Player {
public:
    /// @return an action that was chosen uniformly at random.
    /// The given information set is ignored.
    Action do_betting_action(InformationSet info_set) override;
private:
    std::uniform_int_distribution<uint8_t> action_distribution = std::uniform_int_distribution<uint8_t>(0, NUM_ACTIONS - 1);
    std::mt19937 rng = std::mt19937(std::random_device()());
};


#endif //SIMPLE_POKER_CFR_RANDOM_BOT_H
