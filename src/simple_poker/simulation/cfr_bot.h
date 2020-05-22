#ifndef PYKER_CFR_BOT_H
#define PYKER_CFR_BOT_H


#include "simple_player.h"

#include <map>
#include <random>


/// Chooses actions based on the probability distribution given by the strategy and the information set.
class CfrBot : public SimplePlayer {
public:
    explicit CfrBot(std::map<InformationSet, std::array<double, NUM_ACTIONS>> strategy);
    Action do_betting_action(InformationSet info_set) override;
private:
    std::map<InformationSet, std::array<double, NUM_ACTIONS>> strategy;
    std::mt19937 rng = std::mt19937(std::random_device()());
};


#endif //PYKER_CFR_BOT_H
