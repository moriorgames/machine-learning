#ifndef MORIOR_GAMES_ENTITY_NEURON_H
#define MORIOR_GAMES_ENTITY_NEURON_H

#include <vector>
#include <iostream>
#include "Connection.h"

using namespace std;

namespace MoriorGames {

class Neuron
{
public:
    Neuron(unsigned nextLayer);
    double getOutput() const;
    void setOutput(double output);

private:
    double output;
    vector<Connection *> outputWeights;

    double sigmoid(double x);
};

}

#endif
