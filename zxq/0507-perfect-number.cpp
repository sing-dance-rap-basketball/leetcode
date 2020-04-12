/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start

/**
 * Accepted
    156/156 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }

        int root = (int) sqrt(num);
        int res = 1;
        for (int i = 2; i <= root; ++i) {
            if (num % i == 0) {
                res += (i + num / i);
            }
        }
        return res == num;
    }
};
// @lc code=end

