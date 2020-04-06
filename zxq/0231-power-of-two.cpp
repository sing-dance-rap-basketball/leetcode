/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start

/**
 * Accepted
    1108/1108 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        return (n & (n-1)) == 0;
    }
};
// @lc code=end

