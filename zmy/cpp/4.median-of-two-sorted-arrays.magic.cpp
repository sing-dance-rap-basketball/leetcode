/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        int len = nums1.size() + nums2.size();
        result.reserve(len);
        
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(result));

        if(len == 0) 
            return 0;

        return (len & 1) == 1 ? result[len / 2] : (result[len / 2 - 1] + result[len / 2]) / 2.0;
    }
};

