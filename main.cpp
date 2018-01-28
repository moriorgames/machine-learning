#include "src/MoriorGames/Entity/Layer.h"

#include <iostream>
#include <fstream>

using namespace std;
using MoriorGames::Layer;

// Training image file name
const string training_image_fn = "data/train-images-ubyte";

// Training label file name
const string training_label_fn = "data/train-labels-ubyte";

const int width = 28;

const int height = 28;

const int epochs = 512;

vector<int> mnistImage;

//int alternateMain()
//{
//    ifstream image;
//    image.open(training_image_fn.c_str(), ios::in | ios::binary); // Binary image file
//
//    // Reading file headers
//    char number;
//    for (int i = 1; i <= 16; ++i) {
//        image.read(&number, sizeof(char));
//    }
//
//    // Reading image
//    for (int i = 0; i < INPUT_NEURONS; ++i) {
//        image.read(&number, sizeof(char));
//        if (number == 0) {
//            mnistImage.push_back(0);
//        } else {
//            mnistImage.push_back(1);
//        }
//    }
//
//    auto neuron = new Neuron(mnistImage);
//    neuron->print();
//
//    for (int i = 1; i <= epochs; ++i) {
//
//        neuron->calculateOutput();
////        perceptron();
////        back_propagation();
////        if (square_error() < epsilon) {
////            return i;
////        }
//    }
//
//    return 0;
//}
