#ifndef PYKER_CLI_PLAYER_H
#define PYKER_CLI_PLAYER_H


#include "simple_player.h"


/// A simplified poker player that can be controlled using the command line.
class CliPlayer : public SimplePlayer {
public:
    /// @return an action that was inputted via the command line.
    Action do_betting_action(InformationSet info_set) override;
};


#endif //PYKER_CLI_PLAYER_H
