#pragma once
#include <string>
#include <vector>

struct StockData {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double adjClose;
    long long volume;
};

std::vector<StockData> loadCSV(std::string filename);