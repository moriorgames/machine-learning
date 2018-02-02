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

        // Force the bias node's output to 1.0 (it was the last neuron pushed in this layer):
        layer->back()->setOutput(1.0);

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

void MnistNeuralNetwork::backPropagation(const vector<double> &outputs)
{
    error = calculateRootMeanSquareError(outputs);
    calculateOutputGradient(outputs);
    calculateHiddenGradients(outputs);
    updateInputWeights();
}

void MnistNeuralNetwork::getResults()
{
    auto outputLayer = layers.back();
    cout << "Results: ";
    double max = 0.0;
    for (int i = 0; i < outputLayer->size() - 1; ++i) {
        cout << outputLayer->at(i)->getOutput() << " ";
        if (outputLayer->at(i)->getOutput() > max) {
            max = outputLayer->at(i)->getOutput();
        }
    }
    cout << endl;

    cout << fixed;
    cout << setprecision(5);
    int result = 0;
    for (int i = 0; i < outputLayer->size() - 1; ++i) {
        if (outputLayer->at(i)->getOutput() == max) {
            cout << "Prediction: " << result << endl;
            break;
        }
        result++;
    }
}

unsigned MnistNeuralNetwork::countNextLayerNeurons(int index, const vector<unsigned> &topology)
{
    return index == topology.size() - 1 ? 0 : topology[index + 1];
}

double MnistNeuralNetwork::calculateRootMeanSquareError(const vector<double> &outputs)
{
    auto outputLayer = layers.back();
    double error = 0.0;

    // Root Mean Square Error
    for (int i = 0; i < outputLayer->size() - 1; ++i) {
        double delta = outputs[i] - outputLayer->at(i)->getOutput();
        error += delta * delta;
    }
    error /= outputLayer->size() - 1;
    error = sqrt(error);

//    cout << "Calculate Root Mean Square Error:" << error << endl;

    return error;
}

void MnistNeuralNetwork::calculateOutputGradient(const vector<double> &outputs)
{
    auto outputLayer = layers.back();

    for (unsigned i = 0; i < outputLayer->size() - 1; ++i) {
        outputLayer->at(i)->calculateOutputGradient(outputs[i]);
    }
}

void MnistNeuralNetwork::calculateHiddenGradients(const vector<double> &outputs)
{
    for (unsigned i = layers.size() - 2; i > 0; --i) {
        auto hiddenLayer = layers[i];
        auto nextLayer = layers[i + 1];

        for (auto &layer:*hiddenLayer) {
            layer->calculateHiddenGradient(nextLayer);
        }
    }
}

void MnistNeuralNetwork::updateInputWeights()
{
    // For all layers from outputs to first hidden layer,
    // update connection weights

    for (unsigned i = layers.size() - 1; i > 0; --i) {
        auto layer = layers[i];
        auto previousLayer = layers[i - 1];

        for (unsigned j = 0; j < layer->size() - 1; ++j) {
            layer->at(j)->updateInputWeights(previousLayer);
        }
    }
}
