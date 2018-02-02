#include "src/MoriorGames/Parsers/MnistParser.h"
#include "src/MoriorGames/Services/MnistNeuralNetwork.h"
#include "src/MoriorGames/Definitions.h"

using MoriorGames::MnistParser;
using MoriorGames::MnistNeuralNetwork;

int main()
{
    auto parser = new MnistParser("data/test-images-ubyte", "data/test-labels-ubyte");
    parser->showImageInBinary();

    vector<unsigned> topology{INPUT_NEURONS, HIDDEN_NEURONS, OUTPUT_NEURONS};
    auto net = new MnistNeuralNetwork(topology);

    for (int i = 0; i < EPOCHS; ++i) {
        net->feedForward(parser->getImages());
        net->backPropagation(parser->getLabels());
        net->getResults();
    }

    return 0;
}
