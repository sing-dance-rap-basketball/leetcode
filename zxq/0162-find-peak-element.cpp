/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

/*
    √ Accepted
    √ 59/59 cases passed (4 ms)
    √ Your runtime beats 96.86 % of cpp submissions
    √ Your memory usage beats 82.96 % of cpp submissions (8.5 MB)
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i+1]) {
                return i;
            }
        }
        return nums.size() - 1;
    }
};

