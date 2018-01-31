#include "Layer.h"

using MoriorGames::Layer;

Layer::Layer(const vector<double> &inputs, const vector<double> &outputs)
    : inputs{inputs}, outputs{outputs}
{
    for (int i = 0; i < HIDDEN_NEURONS; ++i) {
        hiddenNeurons.push_back(new Neuron(INPUT_NEURONS));
    }
    for (int i = 0; i < OUTPUT_NEURONS; ++i) {
        outputNeurons.push_back(new Neuron(HIDDEN_NEURONS));
    }
}

void Layer::LearningProcess()
{
    hiddenOutput.clear();
    for (auto hidden:hiddenNeurons) {
        hiddenOutput.push_back(hidden->forwardPropagation(inputs));
    }
    lastOutput.clear();
    for (auto output:outputNeurons) {
        lastOutput.push_back(output->forwardPropagation(hiddenOutput));
    }

    cout << "OO outputVec:" << endl;
    for (auto out:lastOutput) {
        cout << out << " ";
    }
    cout << endl;
    cout << endl;


    cout << "Back Propagation:" << endl;
    for (auto output:outputNeurons) {
        output->backPropagation(lastOutput, outputs);
    }
    cout << endl;

}

void Layer::print()
{
    cout << "Inputs:" << endl;
    for (int i = 1; i <= inputs.size(); ++i) {
        cout << inputs[i];
        if (i % IMAGE_SIZE == 0) {
            cout << endl;
        }
    }

    cout << "Expected: " << endl;
    for (auto output:outputs) {
        cout << output << " ";
    }
    cout << endl;
}
