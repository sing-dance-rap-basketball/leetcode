/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start

/**
 * Accepted
    49/49 cases passed (36 ms)
    Your runtime beats 85.5 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (8.2 MB)
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int j = abs(nums[i]) - 1;
            if (nums[j] > 0) {
                nums[j] *= -1;
            }
            else {
                ans.push_back(abs(nums[i]));
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

