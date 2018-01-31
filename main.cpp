#include "src/MoriorGames/Parsers/MnistParser.h"

using MoriorGames::MnistParser;

int main()
{
    auto parser = new MnistParser("data/test-images-ubyte", "data/test-labels-ubyte");
    parser->showImageInBinary();



    return 0;
}
