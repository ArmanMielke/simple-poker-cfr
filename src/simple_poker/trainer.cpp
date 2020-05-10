#include "trainer.h"

#include <iostream>


void Trainer::train(int num_iterations) {
    Deck deck = {1, 2, 3};
    double utility = 0;

    for (int i = 0; i < num_iterations; i++) {
        shuffle(deck);
        utility += cfr(deck, "", 1, 1);
    }

    std::cout << "Average game value: " << (utility / num_iterations) << std::endl;
    // print nodes
    for (auto const& pair : node_map) {
        pair.second.print();
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

double Trainer::cfr(Deck cards, std::string history, double p0, double p1) {
    int num_actions = history.length();
    int player = num_actions % 2;
    int opponent = 1 - player;

    // return payoff for terminal states
    if (num_actions > 1) {
        bool terminal_pass = history[num_actions - 1] == 'p';
        bool double_bet = history.substr(num_actions - 2, 2) == "bb";
        bool player_card_is_higher = cards[player] > cards[opponent];
        if (terminal_pass) {
            if (history == "pp") {
                return player_card_is_higher ? 1 : -1;
            } else {
                return 1;
            }
        } else if (double_bet) {
            return player_card_is_higher ? 2 : -2;
        }
    }

    InformationSet info_set = std::to_string(cards[player]) + history;
    auto node = get_node(info_set);

    // for each action, recursively call cfr with additional history and probability
    std::array<double, NUM_ACTIONS> strategy = node->second.get_strategy(player == 0 ? p0 : p1);
    std::array<double, NUM_ACTIONS> utilities{};
    double node_utility = 0;
    for (int a = 0; a < NUM_ACTIONS; a++) {
        std::string next_history = history + (a == 0 ? "p" : "b");
        utilities[a] = player == 0
            ? - cfr(cards, next_history, p0 * strategy[a], p1)
            : - cfr(cards, next_history, p0, p1 * strategy[a]);
        node_utility += strategy[a] * utilities[a];
    }

    // for each action, compute and accumulate counterfactual regret
    for (int a = 0; a < NUM_ACTIONS; a++) {
        double regret = utilities[a] - node_utility;
        node->second.regret_sum[a] += (player == 0 ? p1 : p0) * regret;
    }

    return node_utility;
}

std::map<InformationSet, Node>::iterator Trainer::get_node(const InformationSet &info_set) {
    // TODO make this a bit nicer, maybe use a better return type
    auto iter = node_map.find(info_set);
    if (iter == node_map.end()) {
        // node not found => create and insert it
        node_map[info_set] = Node(info_set);
        return node_map.find(info_set);
    } else {
        return iter;
    }
}
