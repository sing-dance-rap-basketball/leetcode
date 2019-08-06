/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

/*
    √ Accepted
    √ 41/41 cases passed (40 ms)
    √ Your runtime beats 41.15 % of cpp submissions
    √ Your memory usage beats 67.44 % of cpp submissions (11.8 MB)
    √ Accepted
    √ 41/41 cases passed (36 ms)
    √ Your runtime beats 83.75 % of cpp submissions
    √ Your memory usage beats 96.51 % of cpp submissions (11.7 MB)
 */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int start, end;
        for (int i = 0; i < nums.size(); ++i) {
            for (; i < nums.size() && nums[i] == 0; ++i);
            start = i;
            for (; i < nums.size() && nums[i] == 1; ++i);
            end = i;
            res = max(res, end - start);
        }
        return res;
    }
};

