/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int nearest = INT_MAX;
        int nearestabs = INT_MAX;
        
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size() - 2; i++) {
            int left = i+1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return target;
                if(abs(sum - target) < nearestabs) {
                    nearestabs = abs(sum - target);
                    nearest = sum;
                }
                if(sum > target) {
                    right --;
                } else {
                    left ++;
                }
            }
        }
        return nearest;
    }
};

