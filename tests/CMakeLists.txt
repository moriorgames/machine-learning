find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(
        ${TEST_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
)

add_executable(
        testsuite
        test.cpp
        MoriorGames/Parsers/FileParserTest.cpp
        MoriorGames/Services/CostFunctionTest.cpp
        MoriorGames/Services/DataTransformerTest.cpp
        MoriorGames/Services/GradientDescentTest.cpp
)

target_link_libraries(
        testsuite
        moriorgames_ml
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

FIND_PROGRAM( GCOV_PATH gcov )
FIND_PROGRAM( LCOV_PATH lcov )
FIND_PROGRAM( GENHTML_PATH genhtml )
FIND_PROGRAM( GCOVR_PATH gcovr PATHS ${CMAKE_SOURCE_DIR}/tests)
