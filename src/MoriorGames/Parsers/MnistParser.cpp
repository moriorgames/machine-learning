#include "MnistParser.h"
#include "../Definitions.h"

using MoriorGames::MnistParser;

MnistParser::MnistParser(const string &imageFile, const string &labelsFile)
    : imageFile{imageFile}, labelsFile{labelsFile}
{
    readImages();
    readLabels();
}

void MnistParser::nextImage()
{
    images.clear();

    // Reading image
    char number;
    for (int i = 0; i < INPUT_NEURONS; ++i) {
        imageFileStream.read(&number, sizeof(char));
        if (number == 0) {
            images.push_back(0);
        } else {
            images.push_back(1);
        }
    }
}
void MnistParser::nextLabel()
{
    labels.clear();

    // Reading labels
    char number;
    labelsFileStream.read(&number, sizeof(char));
    for (int i = 0; i < OUTPUT_NEURONS; ++i) {
        if (i == (int) number) {
            labels.push_back(1.0);
        } else {
            labels.push_back(0.0);
        }
    }
}

void MnistParser::showImageInBinary()
{
    cout << fixed;
    cout << setprecision(0);
    cout << "Displaying expected Outputs: ";
    for (int i = 0; i < OUTPUT_NEURONS; i++) {
        cout << labels[i] << " ";
    }
    cout << endl;

    cout << "Expected number: ";
    for (int i = 0; i < OUTPUT_NEURONS; i++) {
        if (labels[i] == 1.0) {
            cout << i << endl;
        }
    }

    cout << "Displaying Binary image " << endl;
    for (int i = 1; i <= images.size(); ++i) {
        cout << images[i];
        if (i % IMAGE_SIZE == 0) {
            cout << endl;
        }
    }
}

void MnistParser::readImages()
{
    imageFileStream.open(imageFile, ios::in | ios::binary);

    if (imageFileStream.is_open()) {

        // Reading file headers
        char number;
        for (int i = 1; i <= 16; ++i) {
            imageFileStream.read(&number, sizeof(char));
        }

        nextImage();

    } else {
        throw runtime_error("Cannot open file `" + imageFile + "`!");
    }
}

void MnistParser::readLabels()
{
    labelsFileStream.open(labelsFile, ios::in | ios::binary);

    if (labelsFileStream.is_open()) {

        // Reading file headers for Labels
        char number;
        for (int i = 1; i <= 8; ++i) {
            labelsFileStream.read(&number, sizeof(char));
        }

        nextLabel();

    } else {
        throw runtime_error("Cannot open file `" + labelsFile + "`!");
    }
}
