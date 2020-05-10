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

/// Returns +1 if player has a stronger hand than opponent.
/// Returns -1 if player has a weaker hand than opponent.
/// Returns 0 if both hands are of equal strength.
int8_t compare_hands(const Deck& cards, size_t player_card_index) {
    Card player_card = cards[player_card_index];
    Card opponent_card = cards[1 - player_card_index];
    Card community_card = cards[2];

    // player has a straight (if the opponent has a straight, too, then it must be one lower)
    if (player_card == community_card + 1) { return 1; }
    // opponent has a straight (if the player has a straight, too, then it must be one lower)
    if (opponent_card == community_card + 1) { return -1; }
    // player has a straight, opponent doesn't
    if (player_card == community_card - 1) { return 1; }
    // opponent has a straight, player doesn't
    if (opponent_card == community_card - 1) { return -1; }

    // draw (both player's high card is the community card)
    if (player_card < community_card && opponent_card < community_card) {
        return 0;
    }

    // the person with the higher card wins
    if (player_card > opponent_card) {
        return 1;
    } else {
        return -1;
    }
}

double calculate_utility(const History& history, const Deck& cards) {
    size_t len = history.size();
    size_t player_card_index = len % 2;

    bool terminal_pass = history[len - 1] == PASS;
    bool double_bet = history[len - 2] == BET && history[len - 1] == BET;
    if (terminal_pass) {
        if (history[len - 2] == PASS && history[len - 1] == PASS) {
            return compare_hands(cards, player_card_index);
        } else {
            return 1;
        }
    } else if (double_bet) {
        return compare_hands(cards, player_card_index) * 2;
    }

    throw std::domain_error("Unreachable");
}
