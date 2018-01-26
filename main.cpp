#include "src/MoriorGames/Parsers/MnistParser.h"
#include "src/MoriorGames/Services/LinearRegression.h"
#include "src/MoriorGames/Services/MnistNeuralNetwork.h"
#include "src/MoriorGames/Utils/BlockTimer.h"

const size_t c_trainingEpochs = 30;

const size_t c_miniBatchSize = 10;

const float c_learningRate = 3.0f;

using MoriorGames::BlockTimer;

int main()
{
//    std::string train = "tests/fixtures/multi-variable.txt";
//    std::string toResolve = "tests/fixtures/to-resolve.txt";
//    int iterate = 500;
//    double learningRate = 0.01;
//    (new MoriorGames::LinearRegression)->execute(train, toResolve, iterate, learningRate);


    // load the MNIST data if we can
    auto parser = new MoriorGames::MnistParser("data/train-images-ubyte", "data/train-labels-ubyte");
    parser->showRandomCharacterInBinary();

    BlockTimer timer("Training Time:  ");

    auto neuralNetwork = new MoriorGames::MnistNeuralNetwork;
    auto data = parser->getImages();

    // train the network, reporting error before each training
    for (size_t epoch = 0; epoch < c_trainingEpochs; ++epoch) {
        printf("Training epoch %zu / %zu...n", epoch + 1, c_trainingEpochs);
        neuralNetwork->train(data, c_miniBatchSize, c_learningRate);
        std::cout << std::endl;
    }

    return 0;
}
