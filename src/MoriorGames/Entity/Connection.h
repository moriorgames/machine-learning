#ifndef MORIOR_GAMES_ENTITY_CONNECTION_H
#define MORIOR_GAMES_ENTITY_CONNECTION_H

#include <random>

using namespace std;

namespace MoriorGames {

class Connection
{
public:
    Connection();
    double weight;
    double deltaWeight;

private:
    double generateRandom();
};

}

#endif
