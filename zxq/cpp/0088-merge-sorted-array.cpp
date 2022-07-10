/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// /*
//     √ Accepted
//     √ 59/59 cases passed (0 ms)
//     √ Your runtime beats 100 % of cpp submissions
//     √ Your memory usage beats 48.36 % of cpp submissions (8.7 MB)
//     √ Accepted
//     √ 59/59 cases passed (4 ms)
//     √ Your runtime beats 87.88 % of cpp submissions
//     √ Your memory usage beats 73.32 % of cpp submissions (8.6 MB)
//  */
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> temp1 (nums1.begin(), nums1.begin() + m);
//         int i = 0, j = 0, k = 0;
//         while (i < m && j < n) {
//             if (temp1[i] <= nums2[j]) {
//                 nums1[k++] = temp1[i++];
//             }
//             else {
//                 nums1[k++] = nums2[j++];
//             }
//         }
//         while (i < m) {
//             nums1[k++] = temp1[i++];
//         }
//         while (j < n) {
//             nums1[k++] = nums2[j++];
//         }
//         return;
//     }
// };

/*
    Top voted solution
    √ Accepted
    √ 59/59 cases passed (4 ms)
    √ Your runtime beats 87.88 % of cpp submissions
    √ Your memory usage beats 87.98 % of cpp submissions (8.5 MB)
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;
        while (j >= 0) {
            nums1[k--] = i >= 0 && nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
        }
        return;
    }
};