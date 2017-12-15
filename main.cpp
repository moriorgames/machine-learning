#include <iostream>
#include <armadillo>

using namespace std;

int main()
{
    arma::mat inputs(3, 2, arma::fill::ones);

    cout << "Creating a C++ with some linear algebra library (Armadillo)" << endl;

    cout << "inputs" << endl;
    cout << inputs << endl;

    return EXIT_SUCCESS;
}
