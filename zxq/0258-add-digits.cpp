/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start

/**
 * Accepted
    1101/1101 cases passed (4 ms)
    Your runtime beats 49.4 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6 MB)
 */
class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        else if (num % 9 == 0) {
            return 9;
        }
        return num % 9;
    }
};
// @lc code=end

