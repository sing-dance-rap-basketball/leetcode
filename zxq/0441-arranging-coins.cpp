/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
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

