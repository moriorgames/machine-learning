#include "Layer.h"

using MoriorGames::Layer;

Layer::Layer(const vector<double> &inputs, const vector<double> &outputs)
{
    inputNeuron = new Neuron(inputs);
    hiddenNeuron = new Neuron(inputs);
    outputNeuron = new Neuron(outputs);
}

void Layer::print()
{
    cout << "Inputs:" << endl;
    auto inputs = inputNeuron->getInputs();
    for (int i = 1; i <= inputs.size(); ++i) {
        cout << inputs[i];
        if (i % IMAGE_SIZE == 0) {
            cout << endl;
        }
    }

    cout << "Expected: " << endl;
    for (auto expected:outputNeuron->getInputs()) {
        cout << expected << " ";
    }
    cout << endl;
}
