/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

/*
    √ Accepted
    √ 192/192 cases passed (8 ms)
    √ Your runtime beats 66.39 % of cpp submissions
    √ Your memory usage beats 40.2 % of cpp submissions (8.9 MB)
    √ Accepted
    √ 192/192 cases passed (8 ms)
    √ Your runtime beats 66.39 % of cpp submissions
    √ Your memory usage beats 82.39 % of cpp submissions (8.8 MB)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back() || nums.size() == 1) { 
            return nums.front();
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int ml, mr;
            for (ml = m; ml > l && nums[ml] == nums[ml-1]; --ml);
            for (mr = m; mr < r && nums[mr] == nums[mr+1]; ++mr);
            
            if (ml > l && mr < r) {
                if (nums[mr] > nums[mr+1]) { return nums[mr+1]; }
                if (nums[ml] < nums[ml-1]) { return nums[ml]; }
                if (nums[ml] > nums[l]) {
                    l = mr + 1;
                }
                else {
                    r = ml - 1;
                }
            }
            else { 
                if (ml == l && mr == r) {
                    return nums[ml];
                }
                else if (ml == l) {
                    if (nums[mr] > nums[mr+1]) { return nums[mr+1]; }
                    else {
                        l = mr + 1;
                    }
                }
                else if (mr == r) {
                    if (nums[ml] < nums[ml-1]) { return nums[ml]; }
                    else {
                        r = ml - 1;
                    }
                }
            }
        }
        return nums[l];   // not needed
    }
};

