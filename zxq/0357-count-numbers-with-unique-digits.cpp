/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start

/**
 * Accepted
    9/9 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6 MB)
 */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        
        int ans = 10;
        for (int i = 1; i < n; ++i) {
            ans *= (10 - i);
        }

        int temp = 9;
        for (int i = 1; i < n-2; ++i) {
            temp *= (9 - i);
        }
        temp *= (n - 2);

        return ans + temp + countNumbersWithUniqueDigits(n-2);
    }
};
// @lc code=end

