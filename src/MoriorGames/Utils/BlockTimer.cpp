#include "BlockTimer.h"

using MoriorGames::BlockTimer;

BlockTimer::BlockTimer(const char *label)
    : label{label}
{
    start = std::chrono::high_resolution_clock::now();
}

BlockTimer::~BlockTimer()
{
    std::chrono::duration<float> seconds = std::chrono::high_resolution_clock::now() - start;
    printf(" %s %0.2f seconds \n", label, seconds.count());
}
