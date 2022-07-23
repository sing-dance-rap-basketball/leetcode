/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start

/**
 * Accepted
    1336/1336 cases passed (4 ms)
    Your runtime beats 81.26 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        for (; i <= n; ++i) {
            n -= i;
        }

        return i - 1;
    }
};
// @lc code=end

