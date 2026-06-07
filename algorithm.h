#pragma once
#include <vector>
#include <string>
//Kadane's algorithm
struct SubarrayResult {
    double maxSum;
    int startIdx;
    int endIdx;
};

// Stock Buy & Sell
struct ProfitResult {
    double maxProfit;
    int buyIdx;
    int sellIdx;
};

//Container With Most Water
struct WaterResult {
    double maxWater;
    int leftIdx;
    int rightIdx;
};

//Product Except Self
struct ProductResult {
    double minProduct;
    int idx;
};

// function declarations
SubarrayResult kadane(std::vector<double> prices);
ProfitResult bestProfit(std::vector<double> prices);
std::pair<int,int> pairSum     (std::vector<double> prices, double target);
std::string mooreTrend  (std::vector<double> prices);
WaterResult maxWater    (std::vector<double> prices);
ProductResult       riskiestDay (std::vector<double> prices);