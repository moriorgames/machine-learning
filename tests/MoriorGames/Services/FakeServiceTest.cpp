
//Define our Module name (prints at testing)
#define BOOST_TEST_MODULE "BaseClassModule"

//VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>

#include "../../../src/MoriorGames/Services/FakeService.h"
// ------------- Tests Follow --------------
BOOST_AUTO_TEST_CASE( constructors )
{
    MoriorGames::FakeService obj;
    MoriorGames::FakeService obj2;

//Check default constructor
//Use BOOST_CHECK for small equal checks - true or false
    BOOST_CHECK(obj.sqrt(5) == obj2.sqrt(5));
}
