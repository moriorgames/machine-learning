
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Services/FakeService.h"

BOOST_AUTO_TEST_CASE(constructor_fake_service)
{
    MoriorGames::FakeService obj;
    MoriorGames::FakeService obj2;

    BOOST_CHECK(obj.sqrt(5) == obj2.sqrt(5));
}
