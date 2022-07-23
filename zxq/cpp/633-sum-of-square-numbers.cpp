/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start

/**
 * Accepted
    124/124 cases passed (4 ms)
    Your runtime beats 62.88 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.2 MB)
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        // 防止 i * i 溢出的特例
        for (long i = 0; i * i <= c; ++i) {
            int temp = c - i * i;
            int root = (int) sqrt(temp);
            if (root * root == temp) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

