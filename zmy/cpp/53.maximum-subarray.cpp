/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
    void search(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int &sum) {
        if(l==r) {
            mx = lmx = rmx = sum = nums[l];
        } else {
            int m = (l+r)/2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            search(nums, l, m, mx1, lmx1, rmx1, sum1);
            search(nums, m+1, r, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1+lmx2);
            lmx = max(lmx1, sum1+lmx2);
            rmx = max(rmx2, sum2+rmx2);
            sum = sum1+sum2;
        }
    }
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp = nums[0];
        int maxn = nums[0];
        for(int i=1; i<n; i++) {
            if(dp<0) {
                dp = nums[i];
            } else {
                dp = dp + nums[i];
            }
            maxn = max(maxn, dp);
        }
        return maxn;
    }
};

