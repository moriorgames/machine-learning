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
    void LearningProcess();
    void print();

private:
    vector<double> inputs;
    vector<double> outputs;
    vector<double> hiddenOutput;
    vector<double> lastOutput;
    vector<Neuron *> hiddenNeurons;
    vector<Neuron *> outputNeurons;
};

}

#endif
