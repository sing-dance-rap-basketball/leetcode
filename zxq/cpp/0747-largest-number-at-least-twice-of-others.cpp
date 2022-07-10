/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

/* 
    √ Accepted
    √ 250/250 cases passed (4 ms)
    √ Your runtime beats 64.8 % of cpp submissions
    √ Your memory usage beats 70 % of cpp submissions (8.4 MB)
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int max = -1;
        int max_idx = -1;
        int second_max = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > max) {
                second_max = max;
                max = nums[i];
                max_idx = i;
            }
            else {
                if (nums[i] > second_max) {
                    second_max = nums[i];
                }
            }
        }
        if (second_max < 0) {
            exit(-1);
        }
        if (max >= second_max * 2) {
            return max_idx;
        }
        return -1;
    }
};

