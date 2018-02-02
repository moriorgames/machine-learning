#ifndef MORIOR_GAMES_ENTITY_NEURON_H
#define MORIOR_GAMES_ENTITY_NEURON_H

#include <vector>
#include <iostream>
#include <cmath>
#include "Connection.h"
#include "../Definitions.h"

using namespace std;

namespace MoriorGames {

class Neuron;

typedef vector<Neuron *> Layer;

class Neuron
{
public:
    Neuron(unsigned index, unsigned nextLayer);
    void feedForward(Layer *layer);
    void calculateOutputGradient(double output);
    void calculateHiddenGradient(const Layer *nextLayer);
    void updateInputWeights(Layer *previousLayer);
    double getOutput() const;
    const vector<Connection *> &getOutputWeights() const;
    void setOutput(double output);
    void print();

private:
    unsigned index;
    double output;
    double gradient;
    vector<Connection *> outputWeights;

    double activationFunction(double x);
    double activationFunctionDerivative(double x);
    double sumDow(const Layer *nextLayer) const;
    double calculateDeltaWeight(double delta, Neuron *neuron) const;
};

}

#endif
