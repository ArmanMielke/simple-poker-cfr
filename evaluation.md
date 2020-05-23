# Simple Poker Evaluation


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
