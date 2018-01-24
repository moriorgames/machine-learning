#ifndef MORIOR_GAMES_SERVICES_MNIST_NEURAL_NETWORK_H
#define MORIOR_GAMES_SERVICES_MNIST_NEURAL_NETWORK_H

#include "../Parsers/MnistParser.h"

namespace MoriorGames {

class MnistNeuralNetwork
{
public:
    void train(uchar **data, size_t miniBatchSize, float learningRate);
};

}

#endif
