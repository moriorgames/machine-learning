#include "Neuron.h"

using MoriorGames::Neuron;

Neuron::Neuron(unsigned index, unsigned nextLayer)
    : index{index}
{
    for (unsigned i = 0; i < nextLayer; ++i) {
        connections.push_back(new Connection);
    }
}

void Neuron::feedForward(Layer *layer)
{
    double sum = 0.0;

    // Sum the previous layer outputs and add the Bias Neuron output
    for (unsigned i = 0; i < layer->size(); ++i) {
        sum += layer->at(i)->getOutput() * layer->at(i)->getOutputWeights()[index]->weight;
    }

    output = activationFunction(sum);
}

void Neuron::calculateOutputGradient(double output)
{
    double delta = output - this->output;
    gradient = delta * activationFunctionDerivative(output);
}

double Neuron::getOutput() const
{
    return output;
}

const vector<MoriorGames::Connection *> &Neuron::getOutputWeights() const
{
    return connections;
}

void Neuron::setOutput(double output)
{
    this->output = output;
}

void Neuron::print()
{
    cout << "Connection Weights" << endl;
    for (auto connection:connections) {
        cout << connection->weight << endl;
    }
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
    return 1.0 / (1.0 + exp(-x));
}

double Neuron::activationFunctionDerivative(double x)
{
    auto f = activationFunction(x);

    return f * (1 - f);
}

void Neuron::calculateHiddenGradient(const Layer *nextLayer)
{
    double dow = sumDow(nextLayer);
    gradient = dow * activationFunctionDerivative(output);
}

double Neuron::sumDow(const Layer *nextLayer) const
{
    double sum = 0.0;

    // Sum our contributions of the errors at the nodes we feed.

    for (unsigned i = 0; i < nextLayer->size() - 1; ++i) {
        sum += connections[i]->weight * nextLayer->at(i)->gradient;
    }

    return sum;
}

void Neuron::updateInputWeights(Layer *previousLayer)
{
    // The weights to be updated are in the Connection container
    // in the neurons in the preceding layer

    for (auto &neuron:*previousLayer) {
        double oldDeltaWeight = neuron->connections[index]->deltaWeight;

        double newDeltaWeight = calculateDeltaWeight(oldDeltaWeight, neuron);

        neuron->connections[index]->deltaWeight = newDeltaWeight;
        neuron->connections[index]->weight += newDeltaWeight;
    }
}

double Neuron::calculateDeltaWeight(double delta, Neuron *neuron) const
{
    return LEARNING_RATE * neuron->getOutput() * gradient + MOMENTUM * delta;
}
