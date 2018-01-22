
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Parsers/MnistParser.h"

using MoriorGames::MnistParser;

BOOST_AUTO_TEST_CASE(should_be_able_to_instantiate_mnist_parser)
{
    new MnistParser("", "");
}

BOOST_AUTO_TEST_CASE(should_read_mnist_image_file)
{
    auto parser = new MnistParser("data/t10k-images-idx3-ubyte", "");
    parser->readImages();
}
