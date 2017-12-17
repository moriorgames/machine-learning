#ifndef MORIOR_GAMES_SERVICES_DATA_TRANSFORMER_H
#define MORIOR_GAMES_SERVICES_DATA_TRANSFORMER_H

#include <armadillo>
#include <cmath>

namespace MoriorGames {

class DataTransformer
{
public:
    explicit DataTransformer(arma::mat &data);
    arma::mat extractInputs();
    arma::mat extractOutput();
    arma::mat extractHypothesis();
    arma::mat extractNormalizedFeatures();

private:
    arma::mat &data;
};

}

#endif
