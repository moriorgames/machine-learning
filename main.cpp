#include "src/MoriorGames/Services/LinearRegression.h"

#include <string>

int main()
{
    std::string train = "tests/fixtures/multi-variable.txt";
    std::string toResolve = "tests/fixtures/to-resolve.txt";
    int iterate = 500;
    double learningRate = 0.01;
    (new MoriorGames::LinearRegression)->execute(train, toResolve, iterate, learningRate);

    return 0;
}
