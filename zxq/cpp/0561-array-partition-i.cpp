/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 */

/*
    √ Accepted
    √ 81/81 cases passed (76 ms)
    √ Your runtime beats 65.75 % of cpp submissions
    √ Your memory usage beats 78.57 % of cpp submissions (11.3 MB)
 */
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i+=2) {
            res += nums[i];
        }
        return res;
    }
};

