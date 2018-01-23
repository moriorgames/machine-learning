#include "src/MoriorGames/Services/LinearRegression.h"
#include "src/MoriorGames/Parsers/MnistParser.h"

#include <string>

int main()
{
//    std::string train = "tests/fixtures/multi-variable.txt";
//    std::string toResolve = "tests/fixtures/to-resolve.txt";
//    int iterate = 500;
//    double learningRate = 0.01;
//    (new MoriorGames::LinearRegression)->execute(train, toResolve, iterate, learningRate);

    auto parser = new MoriorGames::MnistParser("data/test-image-file-ubyte", "data/test-labels-file-ubyte");
    parser->showRandomCharacterInBinary();

    return 0;
}
