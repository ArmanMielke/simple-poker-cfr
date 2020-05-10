#ifndef PYKER_NODE_H
#define PYKER_NODE_H


#include "constants.h"
#include "information_set.h"


class Node {
public:
    std::array<double, NUM_ACTIONS> regret_sum{};

    Node() = default;
    explicit Node(InformationSet info_set);

    [[nodiscard]] std::array<double, NUM_ACTIONS> get_average_strategy() const;
    [[nodiscard]] std::array<double, NUM_ACTIONS> get_strategy(double realization_weight);
    [[nodiscard]] std::string str() const;
private:
    InformationSet info_set;  // TODO remove
    std::array<double, NUM_ACTIONS> strategy{};
    std::array<double, NUM_ACTIONS> strategy_sum{};
};


#endif //PYKER_NODE_H
