/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start

/**
 * Accepted
    35/35 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int bulbSwitch(int n) {
        int sup = (int) sqrt(__INT_MAX__);
        int i;
        for (i = 1; i <= sup && i * i <= n; ++i);
        return i-1;
    }
};
// @lc code=end

