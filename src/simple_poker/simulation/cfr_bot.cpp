#include "cfr_bot.h"

#include <utility>


CfrBot::CfrBot(std::map<InformationSet, std::array<double, NUM_ACTIONS>> strategy) {
    this->strategy = std::move(strategy);
}

Action CfrBot::do_betting_action(InformationSet info_set) {
    std::discrete_distribution<uint8_t> action_distribution(strategy[info_set].begin(), strategy[info_set].end());
    uint8_t action = action_distribution(rng);
    return static_cast<Action>(action);
}
