#ifndef MORIOR_GAMES_SERVICES_COST_FUNCTION_H
#define MORIOR_GAMES_SERVICES_COST_FUNCTION_H

#include <armadillo>
#include <cmath>

namespace MoriorGames {

class CostFunction
{
public:
    static double computeCost(arma::mat inputs, arma::mat output, arma::mat hypothesis);
};

}

#endif
