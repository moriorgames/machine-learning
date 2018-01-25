
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Entity/Neuron.h"

using MoriorGames::Neuron;

BOOST_AUTO_TEST_CASE(should_be_able_to_construct_neuron)
{
    auto obj = new Neuron;
    float result = 0.f;

    std::cout << obj->getWeight() << std::endl;
    std::cout << obj->getBias() << std::endl;

    BOOST_CHECK(obj->getWeight() > result);
    BOOST_CHECK(obj->getBias() > result);
}
