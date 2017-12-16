find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories(
        ${TEST_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
)

add_executable(
        testsuite
        MoriorGames/Services/FakeServiceTest.cpp
        test.cpp
)

target_link_libraries(
        testsuite
        moriorgames_ml
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
