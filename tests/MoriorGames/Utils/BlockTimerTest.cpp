
#include <boost/test/unit_test.hpp>
#include "../../../src/MoriorGames/Utils/BlockTimer.h"

using MoriorGames::BlockTimer;

BOOST_AUTO_TEST_CASE(should_be_able_print_a_time_elapsed)
{
    BlockTimer timer("Print elapsed time");
}
