#ifndef PYKER_NODE_H
#define PYKER_NODE_H


#include "constants.h"


class Node {
public:
    std::array<double, NUM_ACTIONS> regret_sum{};

    Node() = default;
    explicit Node(InformationSet info_set);

    [[nodiscard]] std::array<double, NUM_ACTIONS> get_average_strategy() const;
    [[nodiscard]] std::array<double, NUM_ACTIONS> get_strategy(double realization_weight);
    void print() const;
private:
    InformationSet info_set;
    std::array<double, NUM_ACTIONS> strategy{};
    std::array<double, NUM_ACTIONS> strategy_sum{};
};


#endif //PYKER_NODE_H
