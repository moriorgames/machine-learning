#ifndef MORIOR_GAMES_ENTITY_NEURON_H
#define MORIOR_GAMES_ENTITY_NEURON_H

#include <armadillo>
#include <random>

namespace MoriorGames {

class Neuron
{
public:
    Neuron();
    float getWeight() const;
    float getBias() const;

private:
    float weight;
    float bias;
    arma::mat inputs;
    float output;

    void randomize();

    float generateRandom();
};

}

#endif
