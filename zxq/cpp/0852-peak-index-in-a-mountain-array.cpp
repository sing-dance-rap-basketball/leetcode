/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

/* 
    √ Accepted
    √ 32/32 cases passed (16 ms)
    √ Your runtime beats 68.07 % of cpp submissions
    √ Your memory usage beats 57.14 % of cpp submissions (9.5 MB)
 */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i;
        for (i = 0; i < A.size() - 1; ++i) {
            if (A[i] > A[i+1]) {
                break;
            }
        }
        return i;
    }
};

