#include "MnistNeuralNetwork.h"

using MoriorGames::MnistNeuralNetwork;

MnistNeuralNetwork::MnistNeuralNetwork(const vector<unsigned> &topology)
{
    unsigned numLayers = topology.size();
    for (unsigned i = 0; i < numLayers; ++i) {
        auto layer = new Layer;
        auto nextLayer = countNextLayerNeurons(i, topology);

        for (unsigned j = 0; j <= topology[i]; ++j) {
            layer->neurons.push_back(new Neuron(nextLayer));
        }
        layers.push_back(layer);
    }
}

void MnistNeuralNetwork::feedForward(const vector<double> &inputs)
{
    assert(inputs.size() == layers[0]->neurons.size() - 1);

    for (unsigned i = 0; i < inputs.size(); ++i) {
        layers[0]->neurons[i]->setOutput(inputs[i]);
    }
}

unsigned MnistNeuralNetwork::countNextLayerNeurons(int index, const vector<unsigned> &topology)
{
    return index == topology.size() - 1 ? 0 : topology[index + 1];
}
