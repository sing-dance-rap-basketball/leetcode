/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start

/**
 * Accepted
    40/40 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    int countDigitOne(int n) {       
        vector<int> powers(10, 1);
        for (int i = 1; i < 10; ++i) {
            powers[i] = powers[i-1] * 10;
        }

        int ans = 0;
        for (int i = 1; i < 10; ++i) {
            if (powers[i-1] > n) break;
            ans += n / powers[i] * powers[i-1];
            ans += min(max(n % powers[i] - powers[i-1] + 1, 0), powers[i-1]);
        }
        if (n >= powers.back()) ans += (n - 999999999);
        return ans;
    }
};
// @lc code=end

