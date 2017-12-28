#ifndef MORIOR_GAMES_SERVICES_GRADIENT_DESCENT_H
#define MORIOR_GAMES_SERVICES_GRADIENT_DESCENT_H

#include <armadillo>

namespace MoriorGames {

class GradientDescent
{
public:
    static arma::mat
    execute(arma::mat inputs, arma::mat output, arma::mat hypothesis, double learningRate, int iterations);
};

}

#endif
