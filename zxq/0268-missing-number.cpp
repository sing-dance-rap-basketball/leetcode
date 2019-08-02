/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

/*
    √ Accepted
    √ 122/122 cases passed (24 ms)
    √ Your runtime beats 81.84 % of cpp submissions
    √ Your memory usage beats 85.62 % of cpp submissions (9.8 MB)
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_all = 0, xor_all_but_missing = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
            xor_all ^= i;
            xor_all_but_missing ^= nums[i];
        }
        xor_all ^= (int)nums.size();
        return xor_all ^ xor_all_but_missing;
    }
};

