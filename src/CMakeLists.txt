find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

MESSAGE(STATUS "Armadillo libraries: ${ARMADILLO_LIBRARIES}")

add_library(
        moriorgames_ml
        MoriorGames/Entity/Neuron.cpp
        MoriorGames/Parsers/FileParser.cpp
        MoriorGames/Parsers/MnistParser.cpp
        MoriorGames/Services/CostFunction.cpp
        MoriorGames/Services/DataTransformer.cpp
        MoriorGames/Services/GradientDescent.cpp
        MoriorGames/Services/LinearRegression.cpp
        MoriorGames/Services/MnistNeuralNetwork.cpp
        MoriorGames/Services/Resolver.cpp
        MoriorGames/Utils/BlockTimer.cpp
        MoriorGames/Entity/Connection.cpp
)

target_link_libraries(moriorgames_ml ${ARMADILLO_LIBRARIES})
