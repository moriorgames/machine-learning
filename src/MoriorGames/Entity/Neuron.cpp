#include "Neuron.h"

using MoriorGames::Neuron;

Neuron::Neuron()
{
    randomize();
}

void Neuron::randomize()
{
    weight = generateRandom();
    bias = generateRandom();
}

float Neuron::generateRandom()
{
    std::mt19937_64 generator;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    generator.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<float> distribution(0, 1);

    return distribution(generator);
}

float Neuron::getWeight() const
{
    return weight;
}

float Neuron::getBias() const
{
    return bias;
}
