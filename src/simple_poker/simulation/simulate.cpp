#include "simulate.h"
#include "simple_poker/game_over_utils.h"

#include <iostream>


void simulate_games(SimplePlayer* player1, SimplePlayer* player2, int num_games) {
    Deck deck;
    std::mt19937 rng = std::mt19937(std::random_device()());

    for (int game = 0; game < num_games; game++) {
        shuffle(deck, rng);
        double utility = simulate_game(player1, player2, deck);
        std::cout << utility << std::endl;
    }
}

double simulate_game(SimplePlayer* player1, SimplePlayer* player2, Deck& deck) {
    History history;
    std::array<SimplePlayer*, 2> players = { player1, player2 };
    size_t current_player = 0; // 0 for player1, 1 for player2

    while (!game_over(history)) {
        InformationSet info_set = { .hand = deck[current_player], .community_card = deck[2], .history = history };
        Action action = players[current_player]->do_betting_action(info_set);
        history.push_back(action);
    }

    return calculate_utility(history, deck);
}
