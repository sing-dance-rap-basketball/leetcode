/**
 * 26. Remove Duplicates from Sorted Array
 * Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 */

/**
 * Runtime: 24 ms, faster than 73.24% of C++ online submissions for Remove Duplicates from Sorted Array.
 * Memory Usage: 10 MB, less than 20.33% of C++ online submissions for Remove Duplicates from Sorted Array.
 * 滑窗的思想(前提是有序) 题目描述中的Clarification还是有点意思的
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = 0, index = 0;
        int size = nums.size();
        if (size == 0)
            return 0;
        while (index < size - 1) {
            if(nums[index] != nums[index+1]) {
                nums[length++] = nums[index];
            }
            ++index;
        }
        nums[length++] = nums[size-1];
        return length;
    }
};