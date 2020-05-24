cmake_minimum_required(VERSION 3.16)
project(simple-poker-cfr)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(cfr
        src/main.cpp

        src/action.h
        src/deck.cpp
        src/deck.h
        src/game_over_utils.cpp
        src/game_over_utils.h
        src/information_set.cpp
        src/information_set.h
        src/node.cpp
        src/node.h
        src/trainer.cpp
        src/trainer.h

        src/simulation/simulate.cpp
        src/simulation/simulate.h
        src/simulation/simple_player.h
        src/simulation/cfr_bot.cpp
        src/simulation/cfr_bot.h
        src/simulation/cli_player.cpp
        src/simulation/cli_player.h
        src/simulation/random_bot.cpp
        src/simulation/random_bot.h
)
