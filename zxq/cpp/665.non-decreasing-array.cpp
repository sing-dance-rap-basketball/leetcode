/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Medium (23.93%)
 * Likes:    4919
 * Dislikes: 724
 * Total Accepted:    223.3K
 * Total Submissions: 933.2K
 * Testcase Example:  '[4,2,3]'
 *
 * Given an array nums with n integers, your task is to check if it could
 * become non-decreasing by modifying at most one element.
 * 
 * We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for
 * every i (0-based) such that (0 <= i <= n - 2).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,2,3]
 * Output: true
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,2,1]
 * Output: false
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // Runtime: 35 ms, faster than 72.00%
    // Memory Usage: 27.1 MB, less than 53.03%
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 3) {return true;}
        int cnt = 0;
        int a = nums[0], b = nums[1];
        for (int i = 2; i < nums.size(); ++i) {
            int c = nums[i];
            if (a <= b) {
                if (b <= c) {
                    a = b;
                    b = c;
                } else if (b > c) {
                    cnt++; 
                    if (a <= c) {
                        a = a;
                        b = c;
                    } else if (a > c) {
                        a = a;
                        b = b;
                    }
                }
            } else if (a > b) { // 只可能是开头的时候
                if (b > c) {
                    return false;
                } else if (b <= c) {
                    cnt++;
                    if (a <= c) {
                        a = a;
                        b = c;
                    } else if (a > c) {
                        a = b;
                        b = c;
                    }
                }
            }

            if (cnt > 1) {return false;}
        }
        return true;
    }
};
// @lc code=end

