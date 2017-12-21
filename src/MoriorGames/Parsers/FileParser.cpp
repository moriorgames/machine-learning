#include "FileParser.h"

using MoriorGames::FileParser;

arma::mat FileParser::load(std::string fileName)
{
    // This size must be fixed
    std::ifstream file(fileName);
    auto rows = getFileRows(file);
    auto cols = getFileCols(file);
    arma::mat data(rows, cols);

    std::string line;
    arma::uword row = 0;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string cell;
        arma::uword col = 0;
        while (std::getline(lineStream, cell, ',')) {
            data(row, col) = stod(cell);
            col++;
        }
        row++;
    }

//    std::cout << "Data:\n" << data << std::endl;

    return data;
}

arma::uword MoriorGames::FileParser::getFileRows(std::ifstream &file)
{
    auto rows = (arma::uword) std::count(
        std::istreambuf_iterator<char>(file),
        std::istreambuf_iterator<char>(), '\n'
    ) + 1;

    file.clear();
    file.seekg(0);

    return rows;
}

arma::uword MoriorGames::FileParser::getFileCols(std::ifstream &file)
{
    std::string line;
    arma::uword cols = 0;
    while (std::getline(file, line)) {
        std::stringstream lineStream(line);
        std::string placeholder;
        while (std::getline(lineStream, placeholder, ','))
            cols++;
        break;
    }

    file.clear();
    file.seekg(0);

    return cols;
}
