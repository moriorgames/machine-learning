#ifndef MORIOR_GAMES_SERVICES_MNIST_NEURAL_NETWORK_H
#define MORIOR_GAMES_SERVICES_MNIST_NEURAL_NETWORK_H

#include <cassert>
#include "../Entity/Layer.h"

using MoriorGames::Layer;

namespace MoriorGames {

class MnistNeuralNetwork
{
public:
    MnistNeuralNetwork(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputs);

private:
    vector<Layer *> layers;

    unsigned countNextLayerNeurons(int index, const vector<unsigned> &topology);
};

}

#endif
