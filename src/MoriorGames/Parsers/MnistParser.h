#ifndef MORIOR_GAMES_PARSERS_MNIST_PARSER_H
#define MORIOR_GAMES_PARSERS_MNIST_PARSER_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

namespace MoriorGames {

class MnistParser
{
public:
    MnistParser(const string &imageFile, const string &labelsFile);
    void nextImage();
    void nextLabel();
    void showImageInBinary();

    vector<double> getImages() const
    {
        return images;
    }

    vector<double> getLabels() const
    {
        return labels;
    }

private:
    string imageFile;
    string labelsFile;
    ifstream imageFileStream;
    ifstream labelsFileStream;
    vector<double> images;
    vector<double> labels;

    void readImages();
    void readLabels();
};

}

#endif
