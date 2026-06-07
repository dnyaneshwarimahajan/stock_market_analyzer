#include "algorithm.h"
#include <algorithm>
#include <climits>
#include <cmath>

// 1. STOCK BUY & SELL
// Find buyday and sellingday so that profit will be maximum
ProfitResult bestProfit(std::vector<double> prices) {

    double minPrice  = prices[0];
    double maxProfit = 0;
    int buyIdx  = 0;
    int sellIdx = 0;
    int tempBuy = 0;
    int n = prices.size();

    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
            tempBuy  = i;
        }

        double profit = prices[i] - minPrice;

        if (profit > maxProfit) {
            maxProfit = profit;
            buyIdx    = tempBuy;
            sellIdx   = i;
        }
    }

    return { maxProfit, buyIdx, sellIdx };
}

// 2. KADANE'S ALGORITHM
// Find the best continuous growth streak(maximum possitive streak)
SubarrayResult kadane(std::vector<double> prices) {
    int n = prices.size();
    std::vector<double> nums;
    for (int i = 1; i < n; i++)
        nums.push_back(prices[i] - prices[i-1]);

    double maxSum = nums[0];
    double currentSum = nums[0];
    int start = 0;
    int end = 0;
    int tempStart = 0;

    for (int i = 1; i < (int)nums.size(); i++) {

        // starting fresh is better than continuing
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            tempStart  = i;
        } else {
            currentSum += nums[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start  = tempStart;
            end    = i;
        }
    }

    return { maxSum, start + 1, end + 1 };
}
// 3. MOORE'S VOTING
// Find dominant market trend - bullish or bearish

std::string mooreTrend(std::vector<double> prices) {

    int n = prices.size();
    int candidate = 1;
    int count     = 0;
    int upDays    = 0;
    int downDays  = 0;

    for (int i = 1; i < n; i++) {

        int vote = (prices[i] >= prices[i-1]) ? 1 : -1;
        if (vote == 1) upDays++;
        else downDays++;

        if (count == 0) {
            candidate = vote;
            count     = 1;
        } else if (vote == candidate) {
            count++;
        } else {
            count--;
        }
    }

    std::string trend;
    if (candidate == 1)
        trend = "BULLISH (UPWARD)";
    else
        trend = "BEARISH (DOWNWARD)";

    return trend + " | Up days: "   + std::to_string(upDays)
                 + " | Down days: " + std::to_string(downDays);
}

// 4. TWO POINTER PAIR SUM
//Find two days whose prices sum to a target

std::pair<int,int> pairSum(std::vector<double> prices, double target) {
    int n = prices.size();

    std::vector<std::pair<double,int>> sorted;
    for (int i = 0; i < n; i++)
        sorted.push_back({ prices[i], i });

    std::sort(sorted.begin(), sorted.end());

    int left  = 0;
    int right = (int)sorted.size() - 1;

    while (left < right) {

        double sum = sorted[left].first + sorted[right].first;

        if (fabs(sum - target) < 1.0)
            return { sorted[left].second, sorted[right].second };
        else if (sum < target)
            left++;
        else
            right--;
    }

    return { -1, -1 };
}

// 5. CONTAINER WITH MOST WATER
// Find two days that hold maximum water (price x distance)

WaterResult maxWater(std::vector<double> prices) {

    int    left  = 0;
    int    right = (int)prices.size() - 1;
    double best  = 0;
    int    bestL = 0;
    int    bestR = 0;

    while (left < right) {
        double water = std::min(prices[left], prices[right]) * (right - left);

        if (water > best) {
            best  = water;
            bestL = left;
            bestR = right;
        }

        if (prices[left] < prices[right])
            left++;
        else
            right--;
    }

    return { best, bestL, bestR };
}
//6.Binary
double binaryExpo(double base, int exp) {

    double result = 1.0;

    while (exp > 0) {

        // odd exponent → multiply result by base
        if (exp % 2 == 1)
            result *= base;

        base *= base;  // square the base
        exp  /= 2;     // halve the exponent
    }

    return result;
}

// 7. PRODUCT EXCEPT SELF
// Find the riskiest day to miss

ProductResult riskiestDay(std::vector<double> prices) {

    int n = (int)prices.size();

    std::vector<double> returns;
    for (int i = 0; i < n - 1; i++)
        returns.push_back(prices[i+1] / prices[i]);

    int m = (int)returns.size();

    std::vector<double> prefix(m, 1.0);
    for (int i = 1; i < m; i++)
        prefix[i] = prefix[i-1] * returns[i-1];

    std::vector<double> suffix(m, 1.0);
    for (int i = m - 2; i >= 0; i--)
        suffix[i] = suffix[i+1] * returns[i+1];

    double minProd = prefix[0] * suffix[0];
    int    minIdx  = 0;

    for (int i = 1; i < m; i++) {
        double p = prefix[i] * suffix[i];
        if (p < minProd) {
            minProd = p;
            minIdx  = i;
        }
    }

    return { minProd, minIdx + 1 };
}