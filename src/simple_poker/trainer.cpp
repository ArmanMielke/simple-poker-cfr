#include "trainer.h"
#include "game_over_utils.h"

#include <iostream>


void Trainer::train(int num_iterations) {
    Deck deck;
    std::iota(std::begin(deck), std::end(deck), 1);
    double utility = 0;

    for (int i = 0; i < num_iterations; i++) {
        shuffle(deck);
        utility += cfr(deck, History(), 1, 1);
    }

    std::cout << "Average game value: " << (utility / num_iterations) << std::endl << std::endl;
    // print average strategy for each information set
    for (auto const& pair : node_map) {
        std::cout << pair.first.str() << "  --  " << pair.second.str() << std::endl;
    }
}

void Trainer::shuffle(Deck& deck) {
    // shuffle cards using Fisher-Yates shuffle
    for (size_t card1_index = deck.size() - 1; card1_index > 0; card1_index--) {
        size_t card2_index = std::uniform_int_distribution<>(0, card1_index)(rng);
        Card tmp = deck[card1_index];
        deck[card1_index] = deck[card2_index];
        deck[card2_index] = tmp;
    }
}

double Trainer::cfr(const Deck& cards, const History& history, double p0, double p1) {
    size_t player = history.size() % 2;

    // return payoff for terminal states
    if (game_over(history)) {
        return calculate_utility(history, cards);
    }

    InformationSet info_set = { .hand = cards[player], .community_card = cards[2], .history = history };
    auto node = get_node(info_set);

    // for each action, recursively call cfr with additional history and probability
    std::array<double, NUM_ACTIONS> strategy = node->second.get_strategy(player == 0 ? p0 : p1);
    std::array<double, NUM_ACTIONS> utilities{};
    double node_utility = 0;
    for (uint8_t action = 0; action < NUM_ACTIONS; action++) {
        // add the new action to the history
        History next_history = History(history);
        next_history.push_back(static_cast<Action>(action));
        // recursively call cfr from the perspective of the other player
        utilities[action] = player == 0
            ? - cfr(cards, next_history, p0 * strategy[action], p1)
            : - cfr(cards, next_history, p0, p1 * strategy[action]);
        node_utility += strategy[action] * utilities[action];
    }

    // for each action, compute and accumulate counterfactual regret
    for (int action = 0; action < NUM_ACTIONS; action++) {
        double regret = utilities[action] - node_utility;
        node->second.regret_sum[action] += (player == 0 ? p1 : p0) * regret;
    }

    return node_utility;
}

std::map<InformationSet, Node>::iterator Trainer::get_node(const InformationSet &info_set) {
    // TODO make this a bit nicer, maybe use a better return type
    auto iter = node_map.find(info_set);
    if (iter == node_map.end()) {
        // node not found => create and insert it
        node_map[info_set] = Node();
        return node_map.find(info_set);
    } else {
        return iter;
    }
}
