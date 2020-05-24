#include "random_bot.h"


Action RandomBot::do_betting_action(InformationSet info_set) {
    uint8_t action = action_distribution(rng);
    return static_cast<Action>(action);
}
