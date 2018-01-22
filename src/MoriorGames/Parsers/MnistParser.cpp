#include "MnistParser.h"

using MoriorGames::MnistParser;

MnistParser::MnistParser(const std::string &images, const std::string &labels)
    : images{images}, labels{labels}
{
}

uchar **MnistParser::readImages()
{
    // Users of Intel processors and other low-endian machines must flip the bytes of the header.
    auto reverseInt = [](int i)
    {
        unsigned char c1, c2, c3, c4;
        c1 = i & 255, c2 = (i >> 8) & 255, c3 = (i >> 16) & 255, c4 = (i >> 24) & 255;
        return ((int) c1 << 24) + ((int) c2 << 16) + ((int) c3 << 8) + c4;
    };

    std::ifstream file(images);

    if (file.is_open()) {
        int magicNumber = 0, rows = 0, cols = 0;

        file.read((char *) &magicNumber, sizeof(magicNumber));
        magicNumber = reverseInt(magicNumber);

        if (magicNumber != 2051) { throw std::runtime_error("Invalid MNIST image file!"); }

        file.read((char *) &numberOfImages, sizeof(numberOfImages)), numberOfImages =
                                                                         reverseInt(numberOfImages);
        file.read((char *) &rows, sizeof(rows)), rows = reverseInt(rows);
        file.read((char *) &cols, sizeof(cols)), cols = reverseInt(cols);

        imageSize = rows * cols;

        uchar **dataset = new uchar *[numberOfImages];
        for (int i = 0; i < numberOfImages; i++) {
            dataset[i] = new uchar[imageSize];
            file.read((char *) dataset[i], imageSize);
        }

        return dataset;
    } else {
        throw std::runtime_error("Cannot open Images file `" + images + "`!");
    }
}
