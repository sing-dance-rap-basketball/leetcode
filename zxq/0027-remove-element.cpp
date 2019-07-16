/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

/*
  √ 113/113 cases passed (4 ms)
  √ Your runtime beats 78.92 % of cpp submissions
  √ Your memory usage beats 81.82 % of cpp submissions (8.5 MB)
  √ 113/113 cases passed (4 ms)
  √ Your runtime beats 78.92 % of cpp submissions
  √ Your memory usage beats 35 % of cpp submissions (8.6 MB)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int curr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[curr++] = nums[i];
            }
        }
        return curr;
    }
};

