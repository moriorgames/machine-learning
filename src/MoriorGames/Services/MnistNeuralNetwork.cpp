#include "MnistNeuralNetwork.h"

using MoriorGames::MnistNeuralNetwork;

MnistNeuralNetwork::MnistNeuralNetwork(const vector<unsigned> &topology)
{
    unsigned numLayers = topology.size();
    for (unsigned i = 0; i < numLayers; ++i) {
        auto layer = new Layer;
        auto nextLayer = countNextLayerNeurons(i, topology);

        for (unsigned j = 0; j <= topology[i]; ++j) {
            layer->push_back(new Neuron(j, nextLayer));
        }
        layers.push_back(layer);
    }
}

void MnistNeuralNetwork::feedForward(const vector<double> &inputs)
{
    assert(inputs.size() == layers[0]->size() - 1);

    for (int i = 0; i < layers.size(); ++i) {
        if (i == 0) {
            for (unsigned j = 0; j < inputs.size(); ++j) {
                layers[i]->at(j)->setOutput(inputs[j]);
            }
        } else {
            auto previousLayer = layers[i - 1];
            for (unsigned j = 0; j < layers[i]->size() - 1; ++j) {
                layers[i]->at(j)->feedForward(previousLayer);
            }
        }
    }
}

unsigned MnistNeuralNetwork::countNextLayerNeurons(int index, const vector<unsigned> &topology)
{
    return index == topology.size() - 1 ? 0 : topology[index + 1];
}
