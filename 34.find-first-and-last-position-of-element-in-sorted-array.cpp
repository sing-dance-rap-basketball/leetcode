/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p = equal_range(nums.begin(), nums.end(), target);
        // std::cout << p.first - nums.begin();
        if(p.first==p.second) {
            return {-1, -1};
        } else {
            return {(p.first - nums.begin()), (p.second - nums.begin() - 1)};
        }
    }
};

