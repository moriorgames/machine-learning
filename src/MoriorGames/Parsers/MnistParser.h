#ifndef MORIOR_GAMES_PARSERS_MNIST_PARSER_H
#define MORIOR_GAMES_PARSERS_MNIST_PARSER_H

#include <string>
#include <fstream>

typedef unsigned char uchar;

namespace MoriorGames {

class MnistParser
{
public:
    MnistParser(const std::string &images, const std::string &labels);
    uchar **readImages();

private:
    std::string images;
    std::string labels;
    int numberOfImages;
    int imageSize;
};

}

#endif
