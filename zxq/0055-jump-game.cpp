/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

/*
× Time Limit Exceeded
  × 74/75 cases passed (N/A)
  × testcase: '[25000,24999,24998,24997,24996, ... ,4,3,2,1,1,0,0]
  × answer: 
  × expected_answer: 
  × stdout:
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) { return false; }
        vector<bool> isCanJump(nums.size(), false);
        isCanJump.back() = true;
        for (int i = isCanJump.size()-2; i >= 0; --i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (isCanJump[i+j]) {
                    isCanJump[i] = true;
                }
            }
            if (i <= nums[0] && isCanJump[i]) {
                return true;
            }
        }
        return isCanJump[0];
    }
};

