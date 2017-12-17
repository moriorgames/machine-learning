
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Parsers/FileParser.h"

using MoriorGames::FileParser;

BOOST_AUTO_TEST_CASE(should_return_matrix_for_single_variable_text)
{
    auto data = (new FileParser)->load("tests/fixtures/single-variable.txt");

    BOOST_CHECK(data.n_cols == 2);
    BOOST_CHECK(data.n_rows == 97);
}

BOOST_AUTO_TEST_CASE(should_return_matrix_for_multi_variable_text)
{
    auto data = (new FileParser)->load("tests/fixtures/multi-variable.txt");

    BOOST_CHECK(data.n_cols == 3);
    BOOST_CHECK(data.n_rows == 47);
}
