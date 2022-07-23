/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// /*
// √ Accepted
//   √ 200/200 cases passed (852 ms)
//   √ Your runtime beats 6.93 % of cpp submissions
//   √ Your memory usage beats 48.4 % of cpp submissions (9.6 MB)
//  */
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxProfit = 0;
//         if (prices.size() <= 1) { return maxProfit; }
//         for (int i = 0; i < prices.size() - 1; ++i) {
//             int tempMaxProfit = 0;
//             for (int j = i+1; j < prices.size(); ++j) {
//                 if (prices[j] - prices[i] > tempMaxProfit) {
//                     tempMaxProfit = prices[j] - prices[i];
//                 }
//             }
//             maxProfit = std::max(maxProfit, tempMaxProfit);
//         }
//         return maxProfit;
//     }
// };

// /*
//     Optimize last solution: 
//     √ Accepted
//     √ 200/200 cases passed (588 ms)
//     √ Your runtime beats 12.93 % of cpp submissions
//     √ Your memory usage beats 47.03 % of cpp submissions (9.6 MB)
//  */
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() <= 1) { return 0; }
//         int maxProfit = 0;
//         int currMinPrice = prices[0];
//         int currMaxIdx = 0;
//         for (int i = 0; i < prices.size() - 1; ++i) {
//             if (i > 0 && prices[i] >= currMinPrice) { continue; }
//             else { currMinPrice = prices[i]; }
//             // in the following, prices[i] = currMinPrice
//             if ( currMaxIdx > i ) { 
//                 maxProfit = std::max(maxProfit, prices[currMaxIdx] - currMinPrice);
//             }
//             else {
//                 currMaxIdx = i + 1;
//                 for (int j = i+2; j < prices.size(); ++j) {
//                     if (prices[j] > prices[currMaxIdx]) {
//                         currMaxIdx = j;
//                     }
//                 }
//                 maxProfit = std::max(maxProfit, prices[currMaxIdx] - currMinPrice);
//             }
//         }
//         return maxProfit;
//     }
// };

// /*
//     Optimize again: 
//     √ Accepted
//   √ 200/200 cases passed (8 ms)
//   √ Your runtime beats 72.67 % of cpp submissions
//   √ Your memory usage beats 13.84 % of cpp submissions (9.7 MB)
//  */
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.size() <= 1) { return 0; }
//         int res = 0;
//         vector<int> lMinIdx(prices.size());  
//         lMinIdx.front() = 0;
//         vector<int> rMaxIdx(prices.size());
//         rMaxIdx.back() = prices.size() - 1;
//         for (int i = 1; i < prices.size(); ++i) {
//             prices[i] < prices[lMinIdx[i-1]] ? lMinIdx[i] = i : lMinIdx[i] = lMinIdx[i-1];
//         }
//         for (int i = prices.size() - 2; i >= 0; --i) {
//             prices[i] > prices[rMaxIdx[i+1]] ? rMaxIdx[i] = i : rMaxIdx[i] = rMaxIdx[i+1];
//         }
//         for (int i = 0; i < prices.size()-1; ++i) {
//             if (lMinIdx[i] == i) {
//                 res = std::max(res, prices[rMaxIdx[i+1]] - prices[i]);
//             }
//         }
//         return res;
//     }
// };

/*
    Solutions above are stupid: 
    √ Accepted
    √ 200/200 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 61.99 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            minPrice = std::min(minPrice, prices[i]);
            res = std::max(res, prices[i] - minPrice);
        }
        return res;
    }
};