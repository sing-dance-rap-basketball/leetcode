/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
/**
 * Accepted
 *  1000/1000 cases passed (0 ms)
 *  Your runtime beats 100 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6.2 MB)
 */
class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) {
            exit(1);
        }

        int ans = 0;
        for (char c : s) {
            ans = ans * 26 + (c - 'A' + 1);
        }

        return ans;
    }
};
// @lc code=end

