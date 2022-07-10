/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

/*
    √ Accepted
    √ 72/72 cases passed (24 ms)
    √ Your runtime beats 98.53 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.8 MB)
 */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) { return 0; }
        int len = nums.size();
        int res = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < len; ++i) {
            if (k == 0) {
                if (i+1 < len && nums[i] == nums[i+1]) {
                    ++res;
                }
                for (; i+1 < len && nums[i] == nums[i+1]; ++i);
            }
            else {  // k > 0
                for (; i+1 < len && nums[i] == nums[i+1]; ++i);
                int target = nums[i] + k;
                j = std::max(i+1, j);
                for (; j < len; ++j) {
                    if (target > nums[j]) {
                        for (; j+1 < len && nums[j] == nums[j+1]; ++j);
                    }
                    else if (target == nums[j]) {
                        ++res;
                        break;
                    }
                    else {  // target < nums[j]
                        break;
                    }
                }
            }
        }
        return res;
    }
};

