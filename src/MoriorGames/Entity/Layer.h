#ifndef MORIOR_GAMES_ENTITY_LAYER_H
#define MORIOR_GAMES_ENTITY_LAYER_H

#include "Neuron.h"

using namespace std;
using MoriorGames::Neuron;

namespace MoriorGames {

class Layer
{
public:
    vector<Neuron *> neurons;
};

}

#endif
