/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

/*
  √ 161/161 cases passed (24 ms)
  √ Your runtime beats 71.39 % of cpp submissions
  √ Your memory usage beats 76.73 % of cpp submissions (9.8 MB)
  √ 161/161 cases passed (20 ms)
  √ Your runtime beats 94.58 % of cpp submissions
  √ Your memory usage beats 30.03 % of cpp submissions (10 MB)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            nums[curr++] = nums[i];
            for (; i+1 < len && nums[i] == nums[i+1]; ++i);
        }
        return curr;
    }
};

