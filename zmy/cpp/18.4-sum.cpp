/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
// TODO: 应该还有可以优化的地方 ...
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::vector<vector<int>> results;
        int n = nums.size();
        if(n < 4)  return results;
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n;j++) {
                int target2 = target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    int sum = nums[left] + nums[right];
                    if(sum > target2) {
                        right --;
                    } else if (sum < target2) {
                        left ++;
                    } else {
                        std::vector<int> tri = {nums[i], nums[j], nums[left], nums[right]};
                        results.push_back(tri);
                        while(left < right && nums[left] == tri[2]) left++;
                        while(left < right && nums[right] == tri[3]) right--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return results;
    }
};

