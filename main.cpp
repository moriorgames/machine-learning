#include "src/MoriorGames/Services/FakeService.h"
#include <iostream>
#include <armadillo>

using MoriorGames::FakeService;
using namespace std;

int main()
{
    arma::mat inputs(3, 2, arma::fill::ones);

    cout << "Creating a C++ with some linear algebra library (Armadillo)" << endl;

    cout << "inputs" << endl;
    cout << inputs << endl;

    cout << "Fake Service sqrt" << endl;
    cout << FakeService::sqrt(5) << endl;

    return EXIT_SUCCESS;
}
