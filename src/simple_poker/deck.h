#ifndef PYKER_DECK_H
#define PYKER_DECK_H


#include <array>
#include <random>


typedef uint8_t Card;
/// This is shuffled, then player 1 gets card deck[0] and player 2 gets card card[1]. card[2] is the community card.
typedef std::array<Card, 13> Deck;

void shuffle(Deck& deck, std::mt19937& rng);


#endif //PYKER_DECK_H
