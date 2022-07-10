/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start

/**
 * Accepted
    68/68 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num;
        while (l <= r) {
            long m = (l + r) / 2;
            if (m * m > num) {
                r = m - 1;
            }
            else if (m * m < num) {
                l = m + 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

