/**
 * 16. 3Sum Closest
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 */

/**
 * 和上一题差不多 反而更简单了……
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        unsigned int size = nums.size();
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int ret = 0;
        for (int i = 0; i < size - 1; ++i) {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            
            int l = i + 1, r = size - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum - target == 0)
                    return sum;
                
                if (abs(sum - target) < closest) {
                    closest = abs(sum - target);
                    ret = sum;
                }
                
                if (sum - target > 0)
                    --r;
                else
                    ++l;
                
            }
        }

        return ret;        
    }
};