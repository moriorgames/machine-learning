#ifndef MORIOR_GAMES_UTILS_BLOCK_TIMER_H
#define MORIOR_GAMES_UTILS_BLOCK_TIMER_H

#include <chrono>
#include <cstdio>

namespace MoriorGames {

struct BlockTimer
{
    explicit BlockTimer(const char *label);

    ~BlockTimer();

    std::chrono::high_resolution_clock::time_point start;
    const char *label;
};

}

#endif
