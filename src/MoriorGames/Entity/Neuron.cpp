#include "Neuron.h"

using MoriorGames::Neuron;

Neuron::Neuron(int kInputs)
    : kInputs{kInputs}
{
    init();
}

double Neuron::forwardPropagation(const vector<double> &inputs)
{
    for (int i = 0; i < inputs.size(); ++i) {
        output += inputs[i] * weights[i];
    }
    output += bias;
    output = sigmoid(output);
//    print(inputs);

    return output;
}

double Neuron::backPropagation(const vector<double> &output, const vector<double> &expected)
{
    vector<double> theta;
    for (int i = 0; i < output.size(); ++i) {
        theta.push_back(output[i] * (1 - output[i]) * (expected[i] - output[i]));
    }

//    double theta = output * (1 - output) * (expected[index] - output);
//
//
//    for (int i = 1; i <= n3; ++i) {
//        theta3[i] = out3[i] * (1 - out3[i]) * (expected[i] - out3[i]);
//    }
//
//    for (int i = 1; i <= n2; ++i) {
//        sum = 0.0;
//        for (int j = 1; j <= n3; ++j) {
//            sum += weights2[i][j] * theta3[j];
//        }
//        theta2[i] = out2[i] * (1 - out2[i]) * sum;
//    }
//
//    for (int i = 1; i <= n2; ++i) {
//        for (int j = 1; j <= n3; ++j) {
//            delta2[i][j] = (learning_rate * theta3[j] * out2[i]) + (momentum * delta2[i][j]);
//            weights2[i][j] += delta2[i][j];
//        }
//    }



    return 0.0;
}

void Neuron::print(const vector<double> &inputs)
{
    cout << "Print neuron:" << endl;
    for (int i = 1; i <= inputs.size(); ++i) {
        cout << (int) inputs[i];
        if (i % IMAGE_SIZE == 0) {
            cout << endl;
        }
    }
}

void Neuron::init()
{
    for (int i = 0; i < kInputs; ++i) {
        weights.push_back(generateRandom());
        deltas.push_back(0);
    }
    output = 0.0;
    bias = 1.0;
}

double Neuron::generateRandom()
{
    mt19937_64 generator;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = chrono::high_resolution_clock::now().time_since_epoch().count();
    seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};
    generator.seed(ss);
    // initialize a uniform distribution between -1 and 1
    uniform_real_distribution<double> distribution(-1, 1);

    return distribution(generator);
}
double Neuron::sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}
