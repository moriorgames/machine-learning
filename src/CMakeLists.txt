find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

MESSAGE(STATUS "Armadillo libraries: ${ARMADILLO_LIBRARIES}")

add_library(
        moriorgames_ml
        MoriorGames/Parsers/FileParser.cpp
        MoriorGames/Services/CostFunction.cpp
        MoriorGames/Services/DataTransformer.cpp
        MoriorGames/Services/GradientDescent.cpp
        MoriorGames/Services/LinearRegression.cpp MoriorGames/Services/LinearRegression.h MoriorGames/Services/Resolver.cpp MoriorGames/Services/Resolver.h)

target_link_libraries(moriorgames_ml ${ARMADILLO_LIBRARIES})
