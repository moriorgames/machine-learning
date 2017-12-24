
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Parsers/FileParser.h"
#include "../../../src/MoriorGames/Services/CostFunction.h"
#include "../../../src/MoriorGames/Services/DataTransformer.h"

using MoriorGames::FileParser;
using MoriorGames::CostFunction;
using MoriorGames::DataTransformer;

BOOST_AUTO_TEST_CASE(cost_function_computed_should_be_near_0_5)
{
    arma::mat inputs(3, 3, arma::fill::ones);
    // This is to keep the matrix structure
    inputs[0] = 120; inputs[3] = 9;
    inputs[1] = -50; inputs[4] = 13;
    inputs[2] = 300; inputs[5] = 6;

    arma::mat output(1, 3, arma::fill::ones);
    output[6] = 1;
    output[7] = 2;
    output[8] = 1.5;

    arma::mat hypothesis(inputs.n_cols, 1, arma::fill::zeros);
    auto disturbance = CostFunction::computeCost(inputs, output, hypothesis);

    BOOST_CHECK(std::abs(disturbance - 0.5) < 0.01);
}
