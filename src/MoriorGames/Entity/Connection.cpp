#include "Connection.h"

using MoriorGames::Connection;

Connection::Connection()
{
    weight = generateRandom();
}

double MoriorGames::Connection::generateRandom()
{
    random_device randomDevice;
    mt19937 seed(randomDevice());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    return distribution(seed);
}
