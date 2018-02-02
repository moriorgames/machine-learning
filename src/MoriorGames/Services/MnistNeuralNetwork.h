#ifndef MORIOR_GAMES_SERVICES_MNIST_NEURAL_NETWORK_H
#define MORIOR_GAMES_SERVICES_MNIST_NEURAL_NETWORK_H

#include <cassert>
#include "../Entity/Neuron.h"

using MoriorGames::Layer;

namespace MoriorGames {

class MnistNeuralNetwork
{
public:
    MnistNeuralNetwork(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputs);
    void backPropagation(const vector<double> &outputs);
    void getResults();

private:
    vector<Layer *> layers;
    double error;

    unsigned countNextLayerNeurons(int index, const vector<unsigned> &topology);
    double calculateRootMeanSquareError(const vector<double> &outputs);
    void calculateOutputGradient(const vector<double> &outputs);
    void calculateHiddenGradients(const vector<double> &outputs);
    void updateInputWeights();
};

}

#endif
