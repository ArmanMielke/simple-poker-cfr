#ifndef PYKER_TRAINER_H
#define PYKER_TRAINER_H


#include "node.h"
#include "information_set.h"

#include <map>
#include <random>


class Trainer {
public:
    /// Trains using CFR, then returns the average strategy over all iterations.
    /// For each information set, the strategy contains a probability distribution over the possible actions,
    /// represented as an array [P(pass), P(bet)].
    [[nodiscard]] std::map<InformationSet, std::array<double, NUM_ACTIONS>> train(int num_iterations);
private:
    std::mt19937 rng = std::mt19937(std::random_device()());
    std::map<InformationSet, Node> node_map;

    double cfr(const Deck& cards, const History& history, double p0, double p1);
    /// Gets the node for the given information set.
    /// The node is created if it doesn't exist yet.
    std::map<InformationSet, Node>::iterator get_node(const InformationSet& info_set);
};


#endif //PYKER_TRAINER_H
