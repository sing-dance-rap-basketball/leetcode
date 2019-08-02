/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

/*
    √ Accepted
    √ 17/17 cases passed (40 ms)
    √ Your runtime beats 82 % of cpp submissions
    √ Your memory usage beats 95.15 % of cpp submissions (12.4 MB)
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int leftProd = 1, rightProd = 1;
        for (int i = 0; i < nums.size()-1; ++i) {
            res[i] = leftProd;
            leftProd *= nums[i];
        }
        res.back() = leftProd;
        for (int i = nums.size()-1; i > 0; --i) {
            res[i] *= rightProd;
            rightProd *= nums[i];
        }
        res.front() *= rightProd;
        return res;
    }
};

