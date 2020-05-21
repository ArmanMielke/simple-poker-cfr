#ifndef PYKER_SIMULATE_H
#define PYKER_SIMULATE_H


#include "simple_player.h"


/// Simulates multiple games, where the starting player alternates between player1 and player2.
/// If num_games is not an even number, an additional game is played so that each player goes first the same number of
/// times.
void simulate_games(SimplePlayer* player1, SimplePlayer* player2, int num_games);

/// Simulates one game with the given deck.
/// Player1 is the starting player.
/// The deck should be shuffled beforehand.
/// @return TODO
[[nodiscard]] double simulate_game(SimplePlayer* player1, SimplePlayer* player2, Deck& deck);


#endif //PYKER_SIMULATE_H
