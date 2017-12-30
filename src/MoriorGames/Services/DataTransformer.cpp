#include "DataTransformer.h"

using MoriorGames::DataTransformer;

DataTransformer::DataTransformer(arma::mat &data)
    : data{data}
{
//    std::cout << "data.n_rows:\n" << data.n_rows << std::endl;
//    std::cout << "data.n_cols:\n" << data.n_cols << std::endl;
}

arma::mat DataTransformer::extractOutput()
{
    arma::mat output = data.col(data.n_cols - 1);

    return output;
}

arma::mat DataTransformer::extractHypothesis()
{
    return arma::mat(data.n_cols, 1, arma::fill::zeros);
}

arma::mat MoriorGames::DataTransformer::extractNormalizedFeatures()
{
    auto inputs = extractInputs();
    arma::mat features(data.n_rows, data.n_cols, arma::fill::ones);

    arma::mat average = arma::mean(inputs);
    arma::mat range = arma::stddev(inputs);

    for (arma::uword i = 1; i < data.n_cols; ++i) {
        features.col(i) = (inputs.col(i) - average[i]) / range[i];
    }

//    std::cout << "average:\n" << average << std::endl;
//    std::cout << "range:\n" << range << std::endl;

    return features;
}

void DataTransformer::setData(arma::mat &data)
{
    this->data = data;
}

arma::mat DataTransformer::extractInputs()
{
    // Add a column of ones to X
    arma::mat inputs(data.n_rows, data.n_cols, arma::fill::ones);

    for (arma::uword i = 1; i < data.n_cols; ++i) {
        inputs.col(i) = data.col(i - 1);
    }

    return inputs;
}
