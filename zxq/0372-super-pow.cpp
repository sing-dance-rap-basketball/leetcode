/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start

/**
 * Accepted
    54/54 cases passed (8 ms)
    Your runtime beats 97.22 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.8 MB)
 */
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        int next = 1;
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            for (int j = 0; j < 10; ++j) {
                if (j == b[i]) {
                    ans = (ans * next) % 1337;
                }
                next = (next * a) % 1337;
            }
            a = next;
            next = 1;
        }
        return ans;
    }
};
// @lc code=end

