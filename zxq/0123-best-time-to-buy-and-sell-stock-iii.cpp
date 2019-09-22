/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// /*
//     × Wrong Answer
//     × 189/200 cases passed (N/A)
//     × Testcase: [1,2,4,2,5,7,2,4,9,0]
//     × Answer: 
//     × Stdout: '12'
//  */
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.empty()) { return 0; }
//         int max = 0, second_max = 0;
//         int i, j = -1;
//         while (true) {
//             for (i = j+1; i < prices.size() - 1 && prices[i] >= prices[i+1]; ++i);
//             for (j = i+1; j < prices.size() - 1 && prices[j] < prices[j+1]; ++j);
//             if (j >= prices.size()) { break; }
            
//             int difference = prices[j] - prices[i];
//             if (difference > max) {
//                 second_max = max;
//                 max = difference;
//             }
//             else {
//                 if (difference > second_max) {
//                     second_max = difference;
//                 }
//             }
//         }
//         return (max + second_max);
//     }
// };

/*
    √ Accepted
    √ 200/200 cases passed (8 ms)
    √ Your runtime beats 70.89 % of cpp submissions
    √ Your memory usage beats 85.71 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) { return 0; }
        vector<int> vp {};  // valleys and peaks
        int i, j = -1;
        while (true) {
            for (i = j+1; i < prices.size() - 1 && prices[i] >= prices[i+1]; ++i);
            for (j = i+1; j < prices.size() - 1 && prices[j] < prices[j+1]; ++j);
            if (j >= prices.size()) { break; }

            vp.push_back(prices[i]);
            vp.push_back(prices[j]);
        }

        if (vp.size() == 0) { return 0; }
        if (vp.size() == 2) { return vp[1] - vp[0]; }
        if (vp.size() == 4) { return vp[1] - vp[0] + vp[3] - vp[2]; }

        int ans = 0;
        for (int cut = 2; cut < vp.size(); cut += 2) {
            int profit_1 = 0, profit_2 = 0;
            int min_price;
            for (int i = 0, min_price = __INT_MAX__; i < cut; ++i) {
                min_price = min(min_price, vp[i]);
                profit_1 = max(profit_1, vp[i] - min_price);
            }
            for (int i = cut, min_price = __INT_MAX__; i < vp.size(); ++i) {
                min_price = min(min_price, vp[i]);
                profit_2 = max(profit_2, vp[i] - min_price);
            }
            ans = max(ans, profit_1 + profit_2);
        }
        return ans;
    }
};

