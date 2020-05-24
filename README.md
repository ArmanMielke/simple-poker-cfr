# Counterfactual Regret Minimization for Simplified Poker


## Rules

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


## Evaluation

- Rand: Bot that chooses its actions uniformly at random
- CFR1: CFR bot trained for 100 iterations (= games)
- CFR2: CFR bot trained for 10,000 iterations
- CFR3: CFR bot trained for 1,000,000 iterations

The table displays how many chips player 1 (row) won against player 2 (column) on average over 1,000,000 games.

|          |   Rand   |   CFR1   |   CFR2   |   CFR3   |
|---------:|:--------:|:--------:|:--------:|:--------:|
|   Rand   | 0.000902 |    --    |    --    |    --    |
|   CFR1   |-0.235421 |-0.007219 |    --    |    --    |
|   CFR2   | 0.019710 | 0.125138 | 0.000522 |    --    |
|   CFR3   | 0.008765 | 0.070699 | 0.007931 | 0.000375 |

The results are NOT averaged over multiple training runs.
In the runs on the diagonal, where the same number of iterations was used for both bots, the bots were trained separately.
This means that they may have converged to different Nash equilibria.

Observations:
- As expected, the entries on the diagonal are almost 0
- Generally, CFR bots trained with more iterations are stronger than CFR bots trained with fewer iterations.
- CFR1 loses a lot of chips against the random bot (I have repeated this experiment multiple times).
- CFR3 does not win against the random bot by a significant amount (I have repeated this experiment, too, and sometimes CFR3 even loses).

