#ifndef SIMPLE_POKER_CFR_CLI_PLAYER_H
#define SIMPLE_POKER_CFR_CLI_PLAYER_H


#include "player.h"


/// A simplified poker player that can be controlled using the command line.
class CliPlayer : public Player {
public:
    /// @return an action that was inputted via the command line.
    Action do_betting_action(InformationSet info_set) override;
};


#endif //SIMPLE_POKER_CFR_CLI_PLAYER_H
