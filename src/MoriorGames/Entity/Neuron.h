#ifndef MORIOR_GAMES_ENTITY_NEURON_H
#define MORIOR_GAMES_ENTITY_NEURON_H

#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include "../Definitions.h"

using namespace std;

namespace MoriorGames {

class Neuron
{
public:
    Neuron(const vector<int> &inputs);
    double calculateOutput();
    void print();

private:
    vector<int> inputs;
    vector<double> weights;
    vector<double> deltas;
    double output;
    double bias;

    void init();
    double generateRandom();
    double sigmoid(double x);
};

}

#endif
