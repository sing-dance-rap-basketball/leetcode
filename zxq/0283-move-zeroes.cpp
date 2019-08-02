/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

/*
    √ Accepted
    √ 21/21 cases passed (12 ms)
    √ Your runtime beats 97.22 % of cpp submissions
    √ Your memory usage beats 79.83 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l, r;
        for (l = 0; l < nums.size() && nums[l] != 0; ++l);
        for (r = l+1; r < nums.size() && nums[r] == 0; ++r);
        while (r < nums.size()) {
            std::swap(nums[l], nums[r]);
            for (++l; l < nums.size() && nums[l] != 0; ++l);
            for (++r; r < nums.size() && nums[r] == 0; ++r);
        }
        return;
    }
};

