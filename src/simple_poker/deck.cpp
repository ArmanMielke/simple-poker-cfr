#include "deck.h"


void shuffle(Deck& deck, std::mt19937& rng) {
    // shuffle cards using Fisher-Yates shuffle
    for (size_t card1_index = deck.size() - 1; card1_index > 0; card1_index--) {
        size_t card2_index = std::uniform_int_distribution<>(0, card1_index)(rng);
        Card tmp = deck[card1_index];
        deck[card1_index] = deck[card2_index];
        deck[card2_index] = tmp;
    }
}
