#include "src/MoriorGames/Parsers/MnistParser.h"
#include "src/MoriorGames/Services/MnistNeuralNetwork.h"
#include "src/MoriorGames/Definitions.h"

using MoriorGames::MnistParser;
using MoriorGames::MnistNeuralNetwork;

int main()
{
    auto parser = new MnistParser("data/test-images-ubyte", "data/test-labels-ubyte");
    parser->showImageInBinary();

    vector<unsigned > topology{3, 2, 1};
    auto net = new MnistNeuralNetwork(topology);
    net->feedForward(parser->getImages());




    return 0;
}
