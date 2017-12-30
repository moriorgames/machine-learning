#ifndef MORIOR_GAMES_SERVICES_LINEAR_REGRESSION_H
#define MORIOR_GAMES_SERVICES_LINEAR_REGRESSION_H

#include <string>

namespace MoriorGames {

class LinearRegression
{
public:
    void execute(const std::string &train, const std::string &resolve, int iterate = 400, double learningRate = 0.01);
};

}

#endif
