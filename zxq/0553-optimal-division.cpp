/*
 * @lc app=leetcode id=553 lang=cpp
 *
 * [553] Optimal Division
 */

// @lc code=start

/**
 * Accepted
    93/93 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.4 MB)
 */
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) return to_string(nums[0]);

        string ans = to_string(nums[0]) + "/";
        
        if (nums.size() > 2) {
            ans += '(';
        }
        
        for (int i = 1; i < nums.size() - 1; ++i) {
            ans += to_string(nums[i]);
            ans += '/';
        }
        ans += to_string(nums.back());

        if (nums.size() > 2) {
            ans += ')';
        }

        return ans;
    }
};
// @lc code=end

