#include "MnistParser.h"

using MoriorGames::MnistParser;

MnistParser::MnistParser(const std::string &imageFile, const std::string &labelsFile)
{
    readImages(imageFile);
    readLabels(labelsFile);
}

void MnistParser::showRandomCharacterInBinary()
{
    std::cout << "Number of imageFile: " << numberOfImages << std::endl;

    // show a random character
    int ind;

    /* initialize random seed: */
    srand(time(NULL));

    /* generate secret number: */
    ind = rand() % numberOfImages;

    std::cout << "" << std::endl;
    std::cout << "Opening a  example: " << std::endl;
    std::cout << +labels[ind] << std::endl;
    std::cout << "" << std::endl;

    // 28 rows
    for (int i = 0; i < 28; i++) {
        // 28 cols
        for (int j = 0; j < 28; j++) {
            if (images[ind][i * 28 + j] > 80) {
                std::cout << ".";
            } else {
                std::cout << "#";
            }
        }
        std::cout << "" << std::endl;
    }

}

void MnistParser::readImages(const std::string &filename)
{
    std::ifstream file(filename);

    if (file.is_open()) {
        int magicNumber = 0, rows = 0, cols = 0;

        file.read((char *) &magicNumber, sizeof(magicNumber));
        magicNumber = reverseInteger(magicNumber);

        if (magicNumber != 2051) { throw std::runtime_error("Invalid MNIST image file!"); }

        file.read((char *) &numberOfImages, sizeof(numberOfImages)), numberOfImages =
                                                                         reverseInteger(numberOfImages);
        file.read((char *) &rows, sizeof(rows)), rows = reverseInteger(rows);
        file.read((char *) &cols, sizeof(cols)), cols = reverseInteger(cols);

        imageSize = rows * cols;

        images = new uchar *[numberOfImages];
        for (int i = 0; i < numberOfImages; i++) {
            images[i] = new uchar[imageSize];
            file.read((char *) images[i], imageSize);
        }

    } else {
        throw std::runtime_error("Cannot open Images file `" + filename + "`!");
    }
}

void MnistParser::readLabels(const std::string &filename)
{
    std::ifstream file(filename, std::fstream::in);

    if (file.is_open()) {
        int magicNumber = 0, nImages = 0;

        file.read((char *) &magicNumber, sizeof(magicNumber));
        magicNumber = reverseInteger(magicNumber);

        if (magicNumber != 2049) { throw std::runtime_error("Invalid MNIST image file!"); }

        file.read((char *) &nImages, sizeof(nImages)), nImages = reverseInteger(nImages);

        if (numberOfImages
            != nImages) { throw std::runtime_error("Labels don't correspond to the previous dataset!"); }

        labels = new uchar[numberOfImages]();

        uchar uch;
        int i = 0;

        while (file >> std::noskipws >> uch) {
            labels[i++] = uch;
        }

    } else {
        throw std::runtime_error("Cannot open file `" + filename + "`!");
    }
}

int MnistParser::reverseInteger(int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;

    return ((int) ch1 << 24) + ((int) ch2 << 16) + ((int) ch3 << 8) + ch4;
}
