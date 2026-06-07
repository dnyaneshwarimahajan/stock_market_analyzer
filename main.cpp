#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "csv_reader.h"
#include "algorithm.h"

int main() {

    std::vector<StockData> data = loadCSV("GOOGL_2025_2026.csv");

    if (data.empty()) {
        std::cout << "Error: File not found!" << std::endl;
        return 1;
    }

    // std::cout << "Loaded " << data.size() << " trading days" << std::endl;

    //Extract closing prices
    std::vector<double> prices;
    for (int i = 0; i < (int)data.size(); i++)
        prices.push_back(data[i].close);

    int n = (int)prices.size();

    std::ofstream file("GOOGL_Report.txt");

    #define WRITE(x) std::cout << x; file << x;

    WRITE("******************************************************************\n")
    WRITE("        GOOGLE STOCK MARKET REPORT 25-26\n")
    WRITE("******************************************************************\n\n")

    WRITE("  Period : " << data.front().date << " to " << data.back().date << "\n")
    WRITE("  Total Days : " << n << "\n")
    WRITE("  Start Price : $" << prices.front() << "\n")
    WRITE("  End Price : $" << prices.back()  << "\n\n")

    WRITE("_________________________________________________________________\n")
    WRITE(" [1] STOCK BUY & SELL - Maximum Profit\n")
    ProfitResult p = bestProfit(prices);
    WRITE("  Max Profit : $" << p.maxProfit << "\n")
    WRITE("  Buy  Date : " << data[p.buyIdx].date  << "($" << prices[p.buyIdx]  << ")\n")
    WRITE("  Sell Date : " << data[p.sellIdx].date << "($" << prices[p.sellIdx] << ")\n\n")

    WRITE("-_________________________________________________________________\n")
    WRITE(" [2] KADANE'S ALGORITHM - Best Growth Streak\n")
    SubarrayResult k = kadane(prices);
    WRITE("  Max Growth : $" << k.maxSum << "\n")
    WRITE("  Streak Start : " << data[k.startIdx].date << "  ($" << prices[k.startIdx] << ")\n")
    WRITE("  Streak End : " << data[k.endIdx].date   << "  ($" << prices[k.endIdx]   << ")\n\n")

    WRITE("___________________________________________________________________\n")
    WRITE(" [3] MOORE'S VOTING - Dominant Market Trend\n")
    std::string trend = mooreTrend(prices);
    WRITE("  Trend : " << trend << "\n\n")

    WRITE("___________________________________________________________________\n")
    WRITE(" [4] TWO POINTER PAIR SUM \n")
    double target = (prices.front() + prices.back());
    auto pair     = pairSum(prices, target);
    if (pair.first != -1) {
        WRITE("  Target : $" << target << "\n")
        WRITE("  Day 1 : " << data[pair.first].date  << "($" << prices[pair.first]  << ")\n")
        WRITE("  Day 2 : " << data[pair.second].date << "($" << prices[pair.second] << ")\n\n")
    } else {
        WRITE("  No pair found for target $" << target << "\n\n")
    }

    WRITE("____________________________________________________________________\n")
    WRITE(" [5] Max Revenue Window\n")
    WaterResult w = maxWater(prices);
    WRITE("  Max Water : " << w.maxWater << "\n")
    WRITE("  Left Date : " << data[w.leftIdx].date  << "  ($" << prices[w.leftIdx]  << ")\n")
    WRITE("  Right Date : " << data[w.rightIdx].date << "  ($" << prices[w.rightIdx] << ")\n")
    WRITE("  Window Span : " << (w.rightIdx - w.leftIdx) << " days\n\n")


    WRITE("__________________________________________________________________________\n")
    WRITE(" [6]Riskiest Day To Miss\n")
    ProductResult r = riskiestDay(prices);
    WRITE("  Riskiest Day : " << data[r.idx].date << "  ($" << prices[r.idx] << ")\n\n")

    WRITE("***********************************************************************\n")
    WRITE("  SUMMARY\n")

    WRITE("  Best Buy : " << data[p.buyIdx].date  << " $" << prices[p.buyIdx]  << "\n")
    WRITE("  Best Sell : " << data[p.sellIdx].date << "$" << prices[p.sellIdx] << "\n")
    WRITE("  Max Profit : $" << p.maxProfit << "\n")
    WRITE("  Market Trend : " << trend << "\n")
    WRITE("***********************************************************************\n")
    
    std::cout << "\nReport saved to GOOGL_Report.txt" << std::endl;

    return 0;
}