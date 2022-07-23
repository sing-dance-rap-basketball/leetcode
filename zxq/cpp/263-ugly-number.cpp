/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start

/**
 * Accepted
    1012/1012 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }

        return (num == 1);
    }
};
// @lc code=end

