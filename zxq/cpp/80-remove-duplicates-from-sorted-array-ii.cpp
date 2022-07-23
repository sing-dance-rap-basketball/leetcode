/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

/*
    √ Accepted
    √ 166/166 cases passed (20 ms)
    √ Your runtime beats 13.09 % of cpp submissions
    √ Your memory usage beats 22.78 % of cpp submissions (8.9 MB)
    √ Accepted
    √ 166/166 cases passed (12 ms)
    √ Your runtime beats 87.16 % of cpp submissions
    √ Your memory usage beats 69.27 % of cpp submissions (8.7 MB)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (i+1 < len && nums[i] == nums[i+1]) {
                nums[curr++] = nums[i];
                nums[curr++] = nums[i];
                for (; i+1 < len && nums[i] == nums[i+1]; ++i);
            }
            else {
                nums[curr++] = nums[i];
            }
        }
        return curr;        
    }
};

