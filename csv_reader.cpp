#include "csv_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<StockData> loadCSV(std::string filename) {

    std::vector<StockData> data;
    std::ifstream file(filename);

    // check if file opened
    if (!file.is_open()) {
        std::cout << "Error: Cannot open file!" << std::endl;
        return data;
    }

    std::string line;

    // skip header row
    std::getline(file, line);

    // read each line
    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string date, open, high, low, close, adjClose, volume;

        // split by comma
        std::getline(ss, date,     ',');
        std::getline(ss, open,     ',');
        std::getline(ss, high,     ',');
        std::getline(ss, low,      ',');
        std::getline(ss, close,    ',');
        std::getline(ss, adjClose, ',');
        std::getline(ss, volume,   ',');

        // fill the struct
        StockData s;
        s.date     = date;
        s.open     = stod(open);
        s.high     = stod(high);
        s.low      = stod(low);
        s.close    = stod(close);
        s.adjClose = stod(adjClose);
        s.volume   = stoll(volume);

        data.push_back(s);
    }

    return data;
}