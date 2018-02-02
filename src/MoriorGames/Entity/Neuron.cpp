#include "Neuron.h"

using MoriorGames::Neuron;

Neuron::Neuron(unsigned index, unsigned nextLayer)
    : index{index}
{
    cout << "Made a Neuron" << endl;
    cout << "Index: " << index << " nextLayer: " << nextLayer << endl;
    for (unsigned i = 0; i < nextLayer; ++i) {
        outputWeights.push_back(new Connection);
    }
}

void Neuron::feedForward(Layer *layer)
{
    double sum = 0.0;

    // Sum the previous layer outputs and add the Bias Neuron output
    for (unsigned i = 0; i < layer->size(); ++i) {
        cout << "i: " << i << " Index: " << index << endl;
        sum += layer->at(i)->getOutput() * layer->at(i)->getOutputWeights()[index]->weight;
    }

}

double Neuron::getOutput() const
{
    return output;
}

const vector<MoriorGames::Connection *> &Neuron::getOutputWeights() const
{
    return outputWeights;
}

void Neuron::setOutput(double output)
{
    Neuron::output = output;
}

/**
 * We Compute hyperbolic tangent function as an Activation function
 *
 * @param x
 *
 * @return double
 */
double Neuron::activationFunction(double x)
{
    return tanh(x);
}

double Neuron::activationFunctionDerivative(double x)
{
    return 1.0 - x * x;
}
