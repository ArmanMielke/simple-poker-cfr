#include "game_over_utils.h"

bool game_over(const std::string& history) {
    // both players need to have made at least one action
    return history.length() > 1 && (
            // if the last action was a pass, that means one player folded or both checked => game ends
            history[history.length() - 1] == 'p' ||
            // if the last two actions were bets then the game ends, since each player can bet at most once
            history.substr(history.length() - 2, 2) == "bb"
    );
}

double calculate_utility(const std::string& history, Deck cards) {
    int num_actions = history.length();
    int player = num_actions % 2;
    int opponent = 1 - player;

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
