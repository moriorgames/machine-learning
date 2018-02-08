#include "src/MoriorGames/Parsers/MnistParser.h"
#include "src/MoriorGames/Services/MnistNeuralNetwork.h"
#include "src/MoriorGames/Definitions.h"

using MoriorGames::MnistParser;
using MoriorGames::MnistNeuralNetwork;

int main()
{
    auto parser = new MnistParser("data/train-images-ubyte", "data/train-labels-ubyte");

    vector<unsigned> topology{INPUT_NEURONS, HIDDEN_NEURONS, OUTPUT_NEURONS};
    auto net = new MnistNeuralNetwork(topology);

    for (int images = 0; images < 1000; images++) {

        for (int i = 0; i < EPOCHS; ++i) {
            net->feedForward(parser->getImages());
            net->backPropagation(parser->getLabels());
        }
        parser->showImageInBinary();
        net->getResults();

        parser->nextImage();
        parser->nextLabel();
    }

    return 0;
}
