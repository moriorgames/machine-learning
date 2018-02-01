#ifndef MORIOR_GAMES_PARSERS_MNIST_PARSER_H
#define MORIOR_GAMES_PARSERS_MNIST_PARSER_H

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

namespace MoriorGames {

class MnistParser
{
public:
    MnistParser(const std::string &imageFile, const std::string &labelsFile);
    void showImageInBinary();

    vector<double> getImages() const
    {
        vector<double> images{1, 2, 3};

        return images;
    }

    vector<double> getLabels() const
    {
        return labels;
    }

private:
    vector<double> images;
    vector<double> labels;

    void readImages(const std::string &filename);
    void readLabels(const std::string &filename);
};

}

#endif
