#ifndef MORIOR_GAMES_ENTITY_NEURON_H
#define MORIOR_GAMES_ENTITY_NEURON_H

#include <vector>
#include <iostream>
#include <cmath>
#include "Connection.h"

using namespace std;

namespace MoriorGames {

class Neuron;

typedef vector<Neuron *> Layer;

class Neuron
{
public:
    Neuron(unsigned index, unsigned nextLayer);
    void feedForward(Layer *layer);
    double getOutput() const;
    const vector<Connection *> &getOutputWeights() const;
    void setOutput(double output);

private:
    unsigned index;
    double output;
    vector<Connection *> outputWeights;

    double activationFunction(double x);
    double activationFunctionDerivative(double x);
};

}

#endif
