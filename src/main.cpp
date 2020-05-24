#include "trainer.h"
#include "simulation/cfr_bot.h"
#include "simulation/cli_player.h"
#include "simulation/random_bot.h"
#include "simulation/simulate.h"

#include <iostream>


const int NUM_TRAIN_ITERATIONS = 1000000;

void print_strategy(const std::map<InformationSet, std::array<double, NUM_ACTIONS>>& strategy) {
    // print probabilities for legal actions in each information set
    for (auto const& [info_set, strat] : strategy) {
        std::cout << info_set.str() << "  --  [ ";
        for (double probability : strat) {
            std::cout << std::to_string(probability) + ", ";
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    auto strategy = Trainer().train(NUM_TRAIN_ITERATIONS);

    simulate_games(new CliPlayer(), new CfrBot(strategy), 1000, true);
}
