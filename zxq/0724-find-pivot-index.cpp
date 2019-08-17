/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

/*
    √ Accepted
    √ 741/741 cases passed (24 ms)
    √ Your runtime beats 86.3 % of cpp submissions
    √ Your memory usage beats 66.67 % of cpp submissions (10 MB)
 */
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] + left_sum * 2 == sum) {
                return i;
            }
            else {
                left_sum += nums[i];
            }
        }
        return -1;
    }
};

