/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
/**
 * Accepted
 *  18/18 cases passed (0 ms)
 *  Your runtime beats 100 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6.1 MB)
 */
class Solution {
public:
    string convertToTitle(int n) {
        if (n <= 0) {
            exit(-1);
        }

        string ans;
        if (n <= 26) {
            ans.push_back('A' - 1 + n);
        }
        else {
            ans = convertToTitle((n - 1) / 26);
            n = (n - 1) % 26 + 1;
            ans += convertToTitle(n);
        }
        
        return ans;
    }
};
// @lc code=end

