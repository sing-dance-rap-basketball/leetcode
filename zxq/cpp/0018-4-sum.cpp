/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

/*
  √ 282/282 cases passed (36 ms)
  √ Your runtime beats 61.15 % of cpp submissions
  √ Your memory usage beats 88.11 % of cpp submissions (9 MB)
  √ 282/282 cases passed (28 ms)
  √ Your runtime beats 75.49 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (8.9 MB)
  √ 282/282 cases passed (24 ms)
  √ Your runtime beats 79.24 % of cpp submissions
  √ Your memory usage beats 89.58 % of cpp submissions (9 MB)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        if (len < 4) { return res; }
        for (int i = 0; i < len-3; ++i) {
            for (int j = i+1; j < len-2; ++j) {
                int k = j+1, l = len-1;
                int temp_target = target - nums[i] - nums[j];
                while (k < l) {
                    if (nums[k] + nums[l] < temp_target) {
                        ++k;
                    }
                    else if (nums[k] + nums[l] > temp_target) {
                        --l;
                    }
                    else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
                        for (k += 1; nums[k-1] == nums[k] && k < l; ++k);
                        for (l -= 1; nums[l] == nums[l+1] && k < l; --l);
                    }
                }
                for (; nums[j] == nums[j+1] && j+1 < len-2; ++j);
            }
            for (; nums[i] == nums[i+1] && i+1 < len-3; ++i);
        }
        return res;        
    }
};