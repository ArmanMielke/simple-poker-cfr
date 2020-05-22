#include "cli_player.h"

#include <iostream>


Action CliPlayer::do_betting_action(InformationSet info_set) {
    char action;

    while (true) {
        std::cout << "Hand: " << std::to_string(info_set.hand) << ". [P]ass or [B]et? ";
        std::cin >> action;
        switch (action) {
            case 'p': case 'P':
                return PASS;
            case 'b': case 'B':
                return BET;
        }
    }

    return PASS;
}
