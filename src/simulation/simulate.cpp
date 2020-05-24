#include "simulate.h"
#include "game_over_utils.h"

#include <iostream>


/// Prints msg to std::cout if verbose is true, does nothing otherwise.
void print(const std::string& msg, bool verbose) {
    if (verbose) {
        std::cout << msg << std::endl;
    }
}

double simulate_games(Player* player1, Player* player2, int num_games, bool verbose) {
    Deck deck = create_deck();
    std::mt19937 rng = std::mt19937(std::random_device()());
    double total_p1_utility = 0;

    for (size_t game = 0; game < num_games; game++) {
        shuffle(deck, rng);
        size_t starting_player = game % 2;
        print("\n--- Game " + std::to_string(game) + " ---", verbose);
        total_p1_utility += simulate_game(player1, player2, deck, starting_player, verbose);
        print("Player 1 has won " + std::to_string((int) total_p1_utility) + " chips so far.", verbose);
    }

    std::cout << std::endl
        << "Player 1 has won " << std::to_string((int) total_p1_utility) << " chips over " << std::to_string(num_games)
        << " games (" << std::to_string(total_p1_utility / num_games) << " on average).";
    return total_p1_utility;
}

std::string action_to_string(const Action& action) {
    switch (action) {
        case PASS:
            return "passes";
        case BET:
            return "bets";
    }
    throw std::domain_error("Unreachable");
}

double simulate_game(Player* player1, Player* player2, Deck& deck, size_t starting_player, bool verbose) {
    std::array<Player*, 2> players = { player1, player2 };
    Card community_card = deck[2];
    History history;
    size_t current_player = starting_player; // 0 for player1, 1 for player2

    print("Community card: " + std::to_string(community_card), verbose);

    while (!game_over(history)) {
        // the starting player gets card deck[0], the other player gets card deck[1]
        Card hand = deck[current_player != starting_player];
        InformationSet info_set = { .hand = hand, .community_card = community_card, .history = history };
        Action action = players[current_player]->do_betting_action(info_set);
        print("Player " + std::to_string(current_player + 1) + " " + action_to_string(action) + ".", verbose);
        history.push_back(action);
        current_player = 1 - current_player;
    }

    double result = calculate_utility(history, deck);
    // calculate_utility returns the utility for the starting player. to get the utility for player 1, the result
    // must be flipped if player2 went first.
    if (starting_player == 1) {
        result *= -1;
    }

    if (verbose) {
        // print result
        std::cout << "Player 1 has a " << std::to_string(deck[starting_player]) << ". "
                  << "Player 2 has a " << std::to_string(deck[1 - starting_player]) << "." << std::endl;
        if (result > 0) {
            std::cout << "Player 1 wins " << std::to_string((int) result) << " chip(s)." << std::endl;
        } else if (result < 0) {
            std::cout << "Player 2 wins " << std::to_string((int) - result) << " chip(s)." << std::endl;
        } else {
            std::cout << "The game ends in a draw." << std::endl;
        }
    }

    return result;
}
