/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

/*
  √ 265/265 cases passed (8 ms)
  √ Your runtime beats 82.4 % of cpp submissions
  √ Your memory usage beats 33.27 % of cpp submissions (8.7 MB)
  √ 265/265 cases passed (8 ms)
  √ Your runtime beats 82.4 % of cpp submissions
  √ Your memory usage beats 53.09 % of cpp submissions (8.6 MB)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) { return; }
        int len = nums.size();
        for (int i = len-2; i >= 0; --i) {
            int temp_idx = i;
            int temp_min = INT_MAX;
            for (int j = i+1; j < len; ++j) {
                if (nums[j] > nums[i] && nums[j] < temp_min) {
                    temp_idx = j;
                    temp_min = nums[j];
                }
            }
            if (temp_idx > i) {   // found
                nums[temp_idx] = nums[i];
                nums[i] = temp_min;
                std::sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
        return;
    }
};

