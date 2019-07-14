/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

/*
  √ 2084/2084 cases passed (24 ms)
  √ Your runtime beats 58.67 % of cpp submissions
  √ Your memory usage beats 67.87 % of cpp submissions (9.6 MB)
  √ 2084/2084 cases passed (16 ms)
  √ Your runtime beats 92.73 % of cpp submissions
  √ Your memory usage beats 74.26 % of cpp submissions (9.6 MB)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int half = (m + n) / 2;
        int i = 0, j = 0;
        int halfValue;
        double result;
        while (i + j < half) {
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    halfValue = nums1[i];
                    ++i;
                } 
                else {
                    halfValue = nums2[j];
                    ++j;
                }
            }
            else if (i >= m) {
                j = half - m;
                halfValue = nums2[j-1];
                break;
            }
            else if (j >= n) {
                i = half - n;
                halfValue = nums1[i-1];
                break;
            }
        }
        if ((m + n) % 2 == 0) {
            int middle1 = halfValue, middle2;
            if (i < m && j < n) {
                if (nums1[i] <= nums2[j]) {
                    middle2 = nums1[i];
                }
                else {
                    middle2 = nums2[j];
                }
            }
            else if (i >= m) {
                middle2 = nums2[j];
            }
            else if (j >= n) {
                middle2 = nums1[i];
            }
            result = (middle1 + middle2) / 2.0;
        }
        if ((m + n) % 2 == 1) {
            int middle;
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    middle = nums1[i];
                }
                else {
                    middle = nums2[j];
                }
            }
            else if (i >= m) {
                middle = nums2[j];
            }
            else if (j >= n) {
                middle = nums1[i];
            }
            result = middle * 1.0;
        }
        return result;
    }
};

