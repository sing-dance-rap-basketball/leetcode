/**
 * 15. 3Sum
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * The solution set must not contain duplicate triplets.
 */

/**
 * Runtime: 84 ms, faster than 99.80% of C++ online submissions for 3Sum.
 * Memory Usage: 14.5 MB, less than 87.62% of C++ online submissions for 3Sum.
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unsigned int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if(size < 3)
            return ret;
        for (int i = 0; i < size - 1; ++i) {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            
            int target = 0 - nums[i];
            int l = i + 1, r = size - 1;
            while (l < r) {
                if (nums[l] + nums[r] > target) --r;
                else if (nums[l] + nums[r] < target) ++l;
                else {
                    ret.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    while(l < size - 1 && nums[l] == nums[l+1]) ++l;   
                    while(r > 0 && nums[r] == nums[r - 1])      --r;
                    --r;
                    ++l;
                    
                }
            }
        }

        return ret;
    }
};