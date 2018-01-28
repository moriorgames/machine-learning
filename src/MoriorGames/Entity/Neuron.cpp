#include "Neuron.h"

using MoriorGames::Neuron;

Neuron::Neuron(const vector<double> &inputs)
    : inputs{inputs}
{
    init();
}

const vector<double> &Neuron::getInputs() const
{
    return inputs;
}

double Neuron::calculateOutput()
{
    for (int i = 1; i <= inputs.size(); ++i) {
        output += inputs[i] * weights[i];
    }
    output = sigmoid(output);

    return output;
}

void Neuron::print()
{
    cout << "Image:" << endl;
    for (int i = 1; i <= inputs.size(); ++i) {
        cout << (int) inputs[i];
        if (i % IMAGE_SIZE == 0) {
            cout << endl;
        }
    }
}

void Neuron::init()
{
    for (int i = 1; i <= inputs.size(); ++i) {
        auto rand = generateRandom();
        weights.push_back(rand);
        deltas.push_back(0);
    }
    output = 0.0;
    bias = 0.0;
}

double Neuron::generateRandom()
{
    mt19937_64 generator;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = chrono::high_resolution_clock::now().time_since_epoch().count();
    seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
    generator.seed(ss);
    // initialize a uniform distribution between 0 and 1
    uniform_real_distribution<double> distribution(0, 1);

    return distribution(generator);
}

double Neuron::sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

