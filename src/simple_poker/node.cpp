#include "node.h"


std::array<double, NUM_ACTIONS> Node::get_average_strategy() const {
    std::array<double, NUM_ACTIONS> average_strategy{};
    double normalizing_sum = 0;

    for (double s : strategy_sum) {
        normalizing_sum += s;
    }

    for (size_t action = 0; action < NUM_ACTIONS; action++) {
        if (normalizing_sum > 0) {
            average_strategy[action] = strategy_sum[action] / normalizing_sum;
        } else {
            average_strategy[action] = 1.0 / NUM_ACTIONS;
        }
    }

    return average_strategy;
}

std::array<double, NUM_ACTIONS> Node::get_strategy(double realization_weight) {
    double normalizing_sum = 0;

    for (size_t action = 0; action < NUM_ACTIONS; action++) {
        strategy[action] = regret_sum[action] > 0 ? regret_sum[action] : 0;
        normalizing_sum += strategy[action];
    }

    for (size_t action = 0; action < NUM_ACTIONS; action++) {
        if (normalizing_sum > 0) {
            strategy[action] /= normalizing_sum;
        } else {
            strategy[action] = 1.0 / NUM_ACTIONS;
        }
        strategy_sum[action] += realization_weight * strategy[action];
    }

    return strategy;
}
