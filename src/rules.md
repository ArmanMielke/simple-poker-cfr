# Simplified Poker - Rules

- The deck has 13 cards of one suit
- Each player gets one card, there is one community card
- Each player must bet one chip at the start of the game
- Which player has the stronger hand is determined like this:
    - Two adjacent cards count as a straight
        - A straight always beats a single card
        - If both players have a straight, the higher one wins
    - If no player has a straight, the player with the higher card wins
    - If both player's private cards are lower than the community card, the game ends in a draw
- There is one betting round
    - Players can either pass (=check/fold) or bet one chip (=call/raise)
    - Betting ends after
        - Both players pass
        - Both players bet
        - One player passes after the other player bets
    - The result of the game is summarized in the table below
- During training it is assumed that each player has an infinite supply of chips


Summary of the betting round:

| Player 1 | Player 2 | Player 1 | Payoff                        |
|:--------:|:--------:|:--------:|:------------------------------|
| pass     | pass     |          | +1 to player with better hand |
| pass     | bet      | pass     | +1 to player 2                |
| pass     | bet      | bet      | +2 to player with better hand |
| bet      | pass     |          | +1 to player 1                |
| bet      | bet      |          | +2 to player with better hand |
