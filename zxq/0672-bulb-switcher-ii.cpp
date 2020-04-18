/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start

/**
 * Accepted
    80/80 cases passed (4 ms)
    Your runtime beats 26.06 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0) return 1;

        // m > 0
        if (n == 1) {
            return 2;
        }
        else if (n == 2) {
            if (m == 1) return 3;
            else if (m > 1) return 4;
        }
        else {  // n > 2
            if (m == 1) return 4;
            else if (m == 2) return 7;
        }

        // n > 2 && m > 2
        return 8;
    }
};
// @lc code=end

