/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

/*
  √ 62/62 cases passed (4 ms)
  √ Your runtime beats 99.03 % of cpp submissions
  √ Your memory usage beats 39.44 % of cpp submissions (8.9 MB)
  √ 62/62 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 34.4 % of cpp submissions (8.9 MB)
  √ 62/62 cases passed (8 ms)
  √ Your runtime beats 70.61 % of cpp submissions
  √ Your memory usage beats 87.12 % of cpp submissions (8.8 MB)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            if (target > nums[left] && target < nums[right]) {
                int middle = (left + right) / 2;
                if (target == nums[middle]) {
                    return middle;
                }
                else if (target < nums[middle]) {
                    if (left+1 == middle) {
                        return middle;
                    }
                    left = left + 1;
                    right = middle - 1;
                }
                else {  // target > nums[middle]
                    if (middle+1 == right) {
                        return right;
                    }
                    left = middle + 1;
                    right = right - 1;
                }
            }
            else if (target <= nums[left]) {
                return left;
            }
            else if (target == nums[right]) {
                return right;
            }
            else {  // target > nums[right]
                return right + 1;
            }
        }
        return 0;
    }
};

