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
    Neuron(int kInputs);
    double forwardPropagation(const vector<double> &inputs);
    double backPropagation(const vector<double> &output, const vector<double> &expected);

    int size() const
    {
        return kInputs;
    }

    void setBias(double bias)
    {
        this->bias = bias;
    }
private:

    int kInputs;
    vector<double> weights;
    vector<double> deltas;
    double output;
    double bias;

    void print(const vector<double> &inputs);
    void init();
    double generateRandom();
    double sigmoid(double x);
};

}

#endif
