#include "simple_poker/trainer.h"

#include <iostream>


const int NUM_TRAIN_ITERATIONS = 1000000;

int main() {
    auto strategy = Trainer().train(NUM_TRAIN_ITERATIONS);

    // print average strategy for each information set
    for (auto const& [info_set, strat] : strategy) {
        std::cout << info_set.str() << "  --  [ ";
        for (double probability : strat) {
            std::cout << std::to_string(probability) + ", ";
        }
        std::cout << "]" << std::endl;
    }
}
