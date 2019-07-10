/**
 * 18. 4Sum
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 */
 
/**
 * 这题看到直接烦了 用16题改的……
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unsigned int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        if(size < 4)
            return ret;
        for (int k = 0; k < size - 1; ++k) {
            if(k > 0 && nums[k-1] == nums[k])
                continue;
            
        for (int i = k + 1; i < size - 1; ++i) {
            if(i > k + 1 && nums[i-1] == nums[i])
                continue;
            
            int rest = target - nums[i] - nums[k];
            int l = i + 1, r = size - 1;
            while (l < r) {
                if (nums[l] + nums[r] > rest) --r;
                else if (nums[l] + nums[r] < rest) ++l;
                else {
                    ret.push_back(vector<int> {nums[k], nums[i], nums[l], nums[r]});
                    while(l < size - 1 && nums[l] == nums[l+1]) {
                        ++l;
                    }   
                    while(r > 0 && nums[r] == nums[r - 1])  {
                         --r;
                    }
                    --r;
                    ++l;   
                }
            }
        }
        }//k
        return ret;        
    }
};