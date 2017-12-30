#include "Resolver.h"
#include <iostream>

using MoriorGames::Resolver;

void Resolver::displayResults(arma::mat &data, arma::mat &normalized, arma::mat &prediction)
{
    for (arma::uword row = 0; row < data.n_rows; ++row) {
        data.row(row).col(data.n_cols - 1) = normalized.row(row) * prediction;
    }

    int lastColumnIndex = (int) data.n_cols - 1;
    std::ofstream output_file("result.csv");
    for (arma::uword row = 0; row < data.n_rows; ++row) {
        for (arma::uword col = 0; col < data.n_cols; ++col) {
            if (lastColumnIndex == col) {
                output_file << data.at(row, col);
            } else {
                output_file << data.at(row, col) << ",";
            }
        }
        output_file << std::endl;
    }
}
