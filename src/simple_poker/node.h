#ifndef PYKER_NODE_H
#define PYKER_NODE_H


#include "constants.h"
#include "information_set.h"


class Node {
public:
    std::array<double, NUM_ACTIONS> regret_sum{};

    [[nodiscard]] std::array<double, NUM_ACTIONS> get_average_strategy() const;
    [[nodiscard]] std::array<double, NUM_ACTIONS> get_strategy(double realization_weight);
private:
    std::array<double, NUM_ACTIONS> strategy{};
    std::array<double, NUM_ACTIONS> strategy_sum{};
};


#endif //PYKER_NODE_H
