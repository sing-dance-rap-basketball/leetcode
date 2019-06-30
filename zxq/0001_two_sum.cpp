/**
 * 问题描述
 * 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

/**
 * 提交结果
 * Runtime: 116 ms, faster than 38.84% of C++ online submissions for Two Sum. 
 * Memory Usage: 9 MB, less than 99.19% of C++ online submissions for Two Sum.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        
        for(int i = 0; i < size; ++i){
            int complement = target - nums[i];
            for(int j = i+1; j < size; ++j){
                if(nums[j] == complement){
                    return vector<int>{i, j};
                }
            }
        }
        
        return vector<int>{0,1};
    }
};