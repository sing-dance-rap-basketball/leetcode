/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

/*
    √ Accepted
    √ 201/201 cases passed (8 ms)
    √ Your runtime beats 60.81 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) { return 0; }
        int ans = 0;
        int i, j = -1;
        while (true) {
            for (i = j+1; i < prices.size() - 1 && prices[i] >= prices[i+1]; ++i);
            for (j = i+1; j < prices.size() - 1 && prices[j] < prices[j+1]; ++j);
            if (j >= prices.size()) { break; }
            ans += (prices[j] - prices[i]);
        }
        return ans;
    }
};

