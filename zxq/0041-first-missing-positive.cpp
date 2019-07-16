/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

/*
  √ 165/165 cases passed (4 ms)
  √ Your runtime beats 73.03 % of cpp submissions
  √ Your memory usage beats 68.22 % of cpp submissions (8.6 MB)
  √ 165/165 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 79.76 % of cpp submissions (8.5 MB)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       std::sort(nums.begin(), nums.end());
       int res = 1;
       for (int i = 0; i < nums.size(); ++i) {
           if (nums[i] < res) {
               continue;
           }
           else if (nums[i] == res) {
               ++res;
           }
           else {
               return res;
           }
       }
       return res;
    }
};

