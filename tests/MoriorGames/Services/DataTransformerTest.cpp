
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Services/DataTransformer.h"

using MoriorGames::DataTransformer;

BOOST_AUTO_TEST_CASE(constructor_data_transformer)
{
    arma::mat data(3, 3, arma::fill::ones);
    new DataTransformer(data);
}

BOOST_AUTO_TEST_CASE(data_transformer_should_add_ones_column_to_features)
{
    arma::mat data(3, 3, arma::fill::ones);
    auto obj = new DataTransformer(data);
    auto inputs = obj->extractInputs();

    BOOST_CHECK(inputs[0] == 1);
}

BOOST_AUTO_TEST_CASE(data_transformer_should_extract_last_column_of_outputs)
{
    arma::mat data(3, 3, arma::fill::ones);
    // This is to keep the matrix structure
    data[0] = 120; data[3] = 9; data[6] = 1;
    data[1] = -50; data[4] = 13; data[7] = 2;
    data[2] = 300; data[5] = 6; data[8] = 1.5;
    auto obj = new DataTransformer(data);
    auto outputs = obj->extractOutput();

    BOOST_CHECK(outputs[2] == 1.5);
}

BOOST_AUTO_TEST_CASE(data_transformer_should_create_hypothesis_with_N_rows_as_data_N_columns)
{
    arma::mat data(3, 3, arma::fill::ones);
    auto obj = new DataTransformer(data);
    auto hypothesis = obj->extractHypothesis();

    BOOST_CHECK(data.n_cols == hypothesis.n_rows);
}

BOOST_AUTO_TEST_CASE(data_transformer_normalize_should_normalize_features)
{
    arma::mat data(3, 3, arma::fill::ones);
    // This is to keep the matrix structure
    data[0] = 120; data[3] = 9; data[6] = 1;
    data[1] = -50; data[4] = 13; data[7] = 2;
    data[2] = 300; data[5] = 6; data[8] = 1.5;
    auto obj = new DataTransformer(data);
    auto normalizedData = obj->extractNormalizedFeatures();

    BOOST_CHECK(std::abs(normalizedData[7] - 1.044) < 0.01);
}