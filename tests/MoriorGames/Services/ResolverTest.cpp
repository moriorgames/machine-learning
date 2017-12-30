
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Services/Resolver.h"

using MoriorGames::Resolver;

BOOST_AUTO_TEST_CASE(resolver_has_to_output_values_resolved)
{
    auto customData = arma::mat(1, 3, arma::fill::ones);
    customData[1] = 1650;
    customData[2] = 3;

    auto prediction = arma::mat(3, 1, arma::fill::ones);
    prediction[0] = 334302.1;
    prediction[1] = 100087.1;
    prediction[2] = 3673.5;
    auto resolver = new Resolver;

//    std::cout.precision(1);
//    std::cout.setf(std::ios::fixed);
//    prediction.raw_print(std::cout, "Prediction: \n\t");

//    std::cout << "prediction:\n" << prediction << std::endl;

//    Prediction:
//    334302.1
//    100087.1
//    3673.5


    resolver->displayResults(customData, customData, prediction);
}
