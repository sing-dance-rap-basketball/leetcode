/**
 * 53. Maximum Subarray
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 */

/**
 * Runtime: 304 ms, faster than 5.00% of C++ online submissions for Maximum Subarray.
 * Memory Usage: 9 MB, less than 97.86% of C++ online submissions for Maximum Subarray.
 * 先来个暴力的 分治知道   O(N)的是啥……
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max = INT_MIN;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += nums[j];
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};