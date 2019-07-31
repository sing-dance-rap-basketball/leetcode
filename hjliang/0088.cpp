/**
 * 88. Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 */

/**
 * Runtime: 4 ms, faster than 86.82% of C++ online submissions for Merge Sorted Array.
 * Memory Usage: 8.6 MB, less than 91.10% of C++ online submissions for Merge Sorted Array.
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        
        for (int i = 0; i < m; ++i) {
            if (nums1[i] > nums2[0]) {
                swap(nums1[i],nums2[0]);
                int index = 1;
                while(index < n && nums2[index] < nums2[index - 1]) {
                    swap(nums2[index],nums2[index - 1]);
                    ++index;
                }
            }        
        }
        
        for (int i = 0; i < n; ++i) 
            nums1[i + m] = nums2[i];
    }
};