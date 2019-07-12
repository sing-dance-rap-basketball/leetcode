/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            int target = -nums[i];
            if(target < 0) {
                break;
            }
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum > target) {
                    right --;
                } else if(sum < target) {
                    left ++;
                } else {
                    std::vector<int> tri={nums[i], nums[left], nums[right]};
                    results.push_back(tri);
                    while(left < right && nums[left] == tri[1]) left++;
                    while(left < right && nums[right] == tri[2]) right--;
                }                
            }
            while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        return results;
    }
};

