#include "game_over_utils.h"

#include <stdexcept>


bool game_over(const History& history) {
    size_t len = history.size();
    // both players need to have made at least one action
    return len > 1 && (
        // if the last action was a pass, that means one player folded or both checked => game ends
        history[len - 1] == PASS ||
        // if the last two actions were bets then the game ends, since each player can bet at most once
        (history[len - 2] == BET && history[len - 1] == BET)
    );
}

double calculate_utility(const History& history, Deck cards) {
    int len = history.size();
    int player = len % 2;
    int opponent = 1 - player;

    bool terminal_pass = history[len - 1] == PASS;
    bool double_bet = history[len - 2] == BET && history[len - 1] == BET;
    bool player_card_is_higher = cards[player] > cards[opponent];
    if (terminal_pass) {
        if (history[len - 2] == PASS && history[len - 1] == PASS) {
            return player_card_is_higher ? 1 : -1;
        } else {
            return 1;
        }
    } else if (double_bet) {
        return player_card_is_higher ? 2 : -2;
    }

    throw std::domain_error("Unreachable");
}
