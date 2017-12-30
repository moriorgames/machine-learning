#include "../Parsers/FileParser.h"
#include "CostFunction.h"
#include "DataTransformer.h"
#include "GradientDescent.h"
#include "LinearRegression.h"
#include "Resolver.h"

using MoriorGames::FileParser;
using MoriorGames::CostFunction;
using MoriorGames::DataTransformer;
using MoriorGames::GradientDescent;
using MoriorGames::LinearRegression;

void LinearRegression::execute(const std::string &train, const std::string &resolve, int iterate, double learningRate)
{
    std::cout << "======= Linear Regression =======" << std::endl;
    std::cout << "Training ..." << std::endl;
    auto fileParser = new FileParser;
    auto dataToTrain = fileParser->load(train);

    auto dataTransformer = new DataTransformer(dataToTrain);

    auto inputs = dataTransformer->extractNormalizedFeatures();
    auto output = dataTransformer->extractOutput();
    auto hypothesis = dataTransformer->extractHypothesis();
    auto prediction = GradientDescent::execute(inputs, output, hypothesis, learningRate, iterate);
    std::cout << "Machine Trained!" << std::endl;

    std::cout << "Do our predictions" << std::endl;
    auto dataToResolve = fileParser->load(resolve);
    dataTransformer->setData(dataToResolve);
    auto normalizedData = dataTransformer->extractNormalizedFeatures();
//    std::cout << "normalizedData" << normalizedData << std::endl;

    (new Resolver)->displayResults(dataToResolve, normalizedData, prediction);
}
