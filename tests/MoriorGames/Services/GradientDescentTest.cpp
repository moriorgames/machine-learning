
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Parsers/FileParser.h"
#include "../../../src/MoriorGames/Services/DataTransformer.h"
#include "../../../src/MoriorGames/Services/GradientDescent.h"

using MoriorGames::FileParser;
using MoriorGames::DataTransformer;
using MoriorGames::GradientDescent;

BOOST_AUTO_TEST_CASE(gradient_descent_on_single_variale)
{
    // You can change this values to perform more iterations on Gradient Descent or bigger learning Rate
    int iterations = 10;
    double learningRate = 0.03;

    auto data = (new FileParser)->load("tests/fixtures/single-variable.txt");

    auto dataTransformer = new DataTransformer(data);
    auto inputs = dataTransformer->extractNormalizedFeatures();
    auto output = dataTransformer->extractOutput();
    auto hypothesis = dataTransformer->extractHypothesis();

    auto prediction = GradientDescent::execute(inputs, output, hypothesis, learningRate, iterations);

    BOOST_CHECK(std::abs(prediction[0] - 1.5332) < 0.01);
    BOOST_CHECK(std::abs(prediction[1] - 1.2014) < 0.01);
}

BOOST_AUTO_TEST_CASE(gradient_descent_on_multiple_variables)
{
    // You can change this values to perform more iterations on Gradient Descent or bigger learning Rate
    int iterations = 10;
    double learningRate = 0.03;

    auto data = (new FileParser)->load("tests/fixtures/multi-variable.txt");

    auto dataTransformer = new DataTransformer(data);
    // Here we extract the normalized Features to converge more efficiently
    auto inputs = dataTransformer->extractNormalizedFeatures();
    auto output = dataTransformer->extractOutput();
    auto hypothesis = dataTransformer->extractHypothesis();

    auto prediction = GradientDescent::execute(inputs, output, hypothesis, learningRate, iterations);

    BOOST_CHECK(std::abs(prediction[0] - 89384.2) < 0.1);
    BOOST_CHECK(std::abs(prediction[1] - 26609.9) < 0.1);
    BOOST_CHECK(std::abs(prediction[2] - 12308.4) < 0.1);
}
