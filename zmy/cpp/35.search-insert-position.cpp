/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto p = lower_bound(nums.begin(), nums.end(), target);
        return p-nums.begin();
    }
};

