#include "MnistParser.h"
#include "../Definitions.h"

using MoriorGames::MnistParser;

MnistParser::MnistParser(const string &imageFile, const string &labelsFile)
{
    readImages(imageFile);
    readLabels(labelsFile);
}

void MnistParser::showImageInBinary()
{
    cout << "Displaying Binary image " << endl;
    cout << "Expected Image: ";
    for (int i = 0; i < OUTPUT_NEURONS; i++) {
        if (labels[i] == 1.0) {
            cout << i << endl;
        }
    }

    for (int i = 1; i <= images.size(); ++i) {
        cout << images[i];
        if (i % IMAGE_SIZE == 0) {
            cout << endl;
        }
    }
}

void MnistParser::readImages(const string &filename)
{
    ifstream file(filename, ios::in | ios::binary);

    if (file.is_open()) {

        // Reading file headers
        char number;
        for (int i = 1; i <= 16; ++i) {
            file.read(&number, sizeof(char));
        }

        // Reading image
        for (int i = 0; i < INPUT_NEURONS; ++i) {
            file.read(&number, sizeof(char));
            if (number == 0) {
                images.push_back(0);
            } else {
                images.push_back(1);
            }
        }

    } else {
        throw runtime_error("Cannot open file `" + filename + "`!");
    }
}

void MnistParser::readLabels(const string &filename)
{
    ifstream file(filename, ios::in | ios::binary);

    if (file.is_open()) {

        // Reading file headers for Labels
        char number;
        for (int i = 1; i <= 8; ++i) {
            file.read(&number, sizeof(char));
        }

        // Reading labels
        file.read(&number, sizeof(char));
        for (int i = 0; i < OUTPUT_NEURONS; ++i) {
            if (i == (int) number) {
                labels.push_back(1.0);
            } else {
                labels.push_back(0.0);
            }
        }

    } else {
        throw runtime_error("Cannot open file `" + filename + "`!");
    }
}
