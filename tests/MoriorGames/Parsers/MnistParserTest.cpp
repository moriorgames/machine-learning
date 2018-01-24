
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Parsers/MnistParser.h"

using MoriorGames::MnistParser;

BOOST_AUTO_TEST_CASE(should_be_able_to_read_and_store_mnist_files)
{
    auto parser = new MnistParser("data/test-images-ubyte", "data/test-labels-ubyte");
    parser->showRandomCharacterInBinary();
}

BOOST_AUTO_TEST_CASE(should_throw_exceptions_when_file_not_found)
{
    BOOST_CHECK_THROW(new MnistParser("fake_file", "data/test-labels-ubyte"), std::runtime_error);
    BOOST_CHECK_THROW(new MnistParser("data/test-images-ubyte", "fake_file"), std::runtime_error);
}
