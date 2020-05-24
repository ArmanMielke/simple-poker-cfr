#ifndef SIMPLE_POKER_CFR_NODE_H
#define SIMPLE_POKER_CFR_NODE_H


#include "action.h"
#include "information_set.h"

#include <array>


class Node {
public:
    std::array<double, NUM_ACTIONS> regret_sum{};

    [[nodiscard]] std::array<double, NUM_ACTIONS> get_average_strategy() const;
    [[nodiscard]] std::array<double, NUM_ACTIONS> get_strategy(double realization_weight);
private:
    std::array<double, NUM_ACTIONS> strategy{};
    std::array<double, NUM_ACTIONS> strategy_sum{};
};


#endif //SIMPLE_POKER_CFR_NODE_H
