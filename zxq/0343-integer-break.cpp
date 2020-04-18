/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start

/**
 * Accepted
    50/50 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        vector<int> v(n+1);
        v[2] = 2;
        v[3] = 3;
        for (int i = 4; i <= n; ++i) {
            for (int j = 2; j <= i / 2; ++j) {
                int temp = v[j] * v[i - j];
                v[i] = temp > v[i] ? temp : v[i];
            }
        }

        return v[n];
    }
};
// @lc code=end

