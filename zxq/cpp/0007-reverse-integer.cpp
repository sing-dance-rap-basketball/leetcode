/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN || x == 0) { return 0; }

        int ans = 0;
        int sign = x > 0 ? 1 : -1;
        x *= sign;
        while (x != 0) {
            if (ans > INT_MAX / 10) {
                return 0;
            }
            else if (ans == INT_MAX / 10 && x % 10 > INT_MAX % 10) {
                return 0;
            }
            else {
                ans = ans * 10 + x % 10;
                x /= 10;
            }
        }
        return ans * sign;
    }
};
// @lc code=end

