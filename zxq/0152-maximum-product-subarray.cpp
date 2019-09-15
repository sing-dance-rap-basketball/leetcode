/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

/*
    https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
    √ Accepted
    √ 184/184 cases passed (4 ms)
    √ Your runtime beats 88.62 % of cpp submissions
    √ Your memory usage beats 85 % of cpp submissions (9.1 MB)
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int res = nums[0];
       long imax = nums[0], imin = nums[0];
       for (int i = 1; i < nums.size(); ++i) {
           if (nums[i] < 0) {
               swap(imax, imin);
           }
           imax = max((long)nums[i], imax * nums[i]);
           imin = min((long)nums[i], imin * nums[i]);
           res = max(res, (int)imax);
       }
       return res;
    }
};

