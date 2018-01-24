#ifndef MORIOR_GAMES_PARSERS_MNIST_PARSER_H
#define MORIOR_GAMES_PARSERS_MNIST_PARSER_H

#include <string>
#include <iostream>
#include <fstream>

typedef unsigned char uchar;

namespace MoriorGames {

class MnistParser
{
public:
    MnistParser(const std::string &imageFile, const std::string &labelsFile);
    void showRandomCharacterInBinary();

    uchar **getImages() const
    {
        return images;
    }

    uchar *getLabels() const
    {
        return labels;
    }

private:
    int numberOfImages;
    int imageSize;
    uchar **images;
    uchar *labels;

    void readImages(const std::string &filename);
    void readLabels(const std::string &filename);
    int reverseInteger(int);
};

}

#endif
