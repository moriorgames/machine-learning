#include "CostFunction.h"

using MoriorGames::CostFunction;

double CostFunction::computeCost(arma::mat inputs, arma::mat output, arma::mat hypothesis)
{
    auto m = inputs.n_rows;
    arma::mat sqrtError(m, 1);
    arma::mat prediction = inputs * hypothesis;

    for (int i = 0; i < m; ++i) {
        auto value = std::pow((prediction[i] - output[i]), 2);
        sqrtError[i] = value;
    }

    auto disturbance = 1.f / (2 * m) * arma::accu(sqrtError);

//    std::cout << "prediction:\n" << prediction << std::endl;
//    std::cout << "sqrtError:\n" << sqrtError << std::endl;
//    std::cout << "hypothesis:\n" << hypothesis << std::endl;
//    std::cout << "disturbance:\n" << disturbance << std::endl;

    return disturbance;
}
