/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

/*
  √ 125/125 cases passed (8 ms)
  √ Your runtime beats 85.57 % of cpp submissions
  √ Your memory usage beats 40.51 % of cpp submissions (8.7 MB)
  √ 125/125 cases passed (4 ms)
  √ Your runtime beats 99.53 % of cpp submissions
  √ Your memory usage beats 47.55 % of cpp submissions (8.7 MB)
  √ 125/125 cases passed (8 ms)
  √ Your runtime beats 85.57 % of cpp submissions
  √ Your memory usage beats 97.18 % of cpp submissions (8.5 MB)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        int curr_abs = abs(res - target);
        for (int i = 0; i < len-2; ++i) {
            int nums_i = nums[i];
            int j = i+1, k = len-1;
            while (j < k) {
                int sum = nums_i + nums[j] + nums[k];
                if (sum < target) {
                    if (target - sum < curr_abs) {
                        res = sum;
                        curr_abs = target - sum;
                    }
                    ++j;
                }
                else if (sum > target) {
                    if (sum - target < curr_abs) {
                        res = sum;
                        curr_abs = sum - target;
                    }
                    --k;
                }
                else {
                    return sum; // sum == target
                }
            }
            for (; i+1 < len-2 && nums[i] == nums[i+1]; ++i);
        }
        return res;
    }
};

