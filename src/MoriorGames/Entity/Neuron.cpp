#include "Neuron.h"

using MoriorGames::Neuron;

MoriorGames::Neuron::Neuron(unsigned nextLayer)
{
    cout << "Made a Neuron" << endl;
    cout << "nextLayer: " << nextLayer << endl;
    for (unsigned i = 0; i < nextLayer; ++i) {
        outputWeights.push_back(new Connection);
    }
}

double Neuron::getOutput() const
{
    return output;
}

void Neuron::setOutput(double output)
{
    Neuron::output = output;
}

double Neuron::sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}
