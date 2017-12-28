#include "GradientDescent.h"

using MoriorGames::GradientDescent;

arma::mat
MoriorGames::GradientDescent::execute(
    arma::mat inputs, arma::mat output, arma::mat hypothesis, double learningRate, int iterations
)
{
    auto nRows = inputs.n_rows;
    arma::mat hypothesisHistory(nRows, 1, arma::fill::zeros);

    for (int i = 0; i < iterations; ++i) {

        arma::mat delta = (inputs * hypothesis) - output;
        for (int j = 0; j < inputs.n_cols; ++j) {
            hypothesis[j] = hypothesis[j] - learningRate * 1.f / nRows * arma::accu(delta % inputs.col(j));
        }

//        std::cout << "delta:\n" << delta << std::endl;
//        std::cout << "hypothesis:\n" << hypothesis << std::endl;
    }

    return hypothesis;
}
