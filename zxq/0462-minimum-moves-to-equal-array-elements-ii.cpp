/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start

/**
 * Accepted
    29/29 cases passed (20 ms)
    Your runtime beats 42.27 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (7 MB)
 */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        while (l < r) {
            ans += (nums[r] - nums[l]);
            ++l;
            --r;
        }
        return ans;
    }
};
// @lc code=end

