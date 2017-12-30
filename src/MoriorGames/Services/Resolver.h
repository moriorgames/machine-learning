#ifndef MORIOR_GAMES_SERVICES_LINEAR_RESOLVER_H
#define MORIOR_GAMES_SERVICES_LINEAR_RESOLVER_H

#include <iostream>
#include <armadillo>

namespace MoriorGames {

class Resolver
{
public:
    void displayResults(arma::mat &data, arma::mat &normalized, arma::mat &prediction);
};

}

#endif
