/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

/*
  √ 88/88 cases passed (8 ms)
  √ Your runtime beats 89.47 % of cpp submissions
  √ Your memory usage beats 54.46 % of cpp submissions (10.3 MB)
  √ 88/88 cases passed (12 ms)
  √ Your runtime beats 42.51 % of cpp submissions
  √ Your memory usage beats 81.88 % of cpp submissions (10.2 MB)
  √ 88/88 cases passed (4 ms)
  √ Your runtime beats 99.66 % of cpp submissions
  √ Your memory usage beats 78.23 % of cpp submissions (10.2 MB)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int len = nums.size();
        int left = 0, right = len-1;
        while (left < right) {
            // compare with two ends
            if (target == nums[left]) {
                int i = left;
                for (; i+1 < len && nums[i] == nums[i+1]; ++i);
                return vector<int>{left, i};
            }
            if (target == nums[right]) {
                int i = right;
                for (; i-1 >= 0 && nums[i] == nums[i-1]; --i);
                return vector<int>{i, right};
            }
            // compare with the middle 
            int middle = (left + right) / 2;
            if (target == nums[middle]) {
                int i = middle, j = middle;
                for (; i-1 >= 0 && nums[i] == nums[i-1]; --i);
                for (; j+1 < len && nums[j] == nums[j+1]; ++j);
                return vector<int>{i, j};
            }
            else if (target < nums[middle]) {
                left = left + 1;
                right = middle - 1;
            }
            else {  // target > nums[middle]
                left = middle + 1;
                right = right - 1;
            }
        }
        if (left == right && target == nums[left]) {
            return vector<int>{left, left};
        }
        return vector<int>{-1, -1};
    }
};

