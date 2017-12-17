#ifndef MORIOR_GAMES_PARSERS_FILE_PARSER_H
#define MORIOR_GAMES_PARSERS_FILE_PARSER_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <armadillo>

namespace MoriorGames {

class FileParser
{
public:
    arma::mat load(std::string fileName);
private:
    arma::uword getFileRows(std::ifstream &file);
    arma::uword getFileCols(std::ifstream &file);
};

}

#endif
