#ifndef MORIOR_GAMES_ENTITY_LAYER_H
#define MORIOR_GAMES_ENTITY_LAYER_H

#include <iostream>
#include "Neuron.h"

using namespace std;
using MoriorGames::Neuron;

namespace MoriorGames {

class Layer
{
public:
    Layer(const vector<double> &inputs, const vector<double> &outputs);
    void print();

private:
    Neuron *inputNeuron;
    Neuron *hiddenNeuron;
    Neuron *outputNeuron;
};

}

#endif
