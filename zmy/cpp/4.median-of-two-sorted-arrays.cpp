/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    int kth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k) {
        int m = r1 - l1;
        int n = r2 - l2;
        if( m > n) return kth(nums2, l2, r2, nums1, l1, r1, k);
        else if ( m == 0 ) return nums2[l2 + k - 1];
        else if ( k == 1 ) return min(nums1[l1], nums2[l2]);
        else {
            int j = min (k/2, m);
            int kk = k- j;
            if(nums1[l1 + j - 1] == nums2[l2 + kk - 1]) {
                return nums1[l1 + j - 1];
            } else if (nums1[l1 + j - 1] < nums2[l2 + kk - 1]) {
                return kth(nums1, l1 + j, r1, nums2, l2, r2, k - j);
            } else {
                return kth(nums1, l1, r1, nums2, l2 + kk, r2, k - kk);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (nums1.size() + nums2.size()) / 2;
        int num1 = kth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k+1);
        if (((nums1.size() + nums2.size()) & 1) == 0) {
            int num2 = kth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k);
            return (num1 + num2)/2.0;
        } else 
            return num1;
    }
};
