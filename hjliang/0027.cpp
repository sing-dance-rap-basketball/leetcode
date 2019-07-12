/**
 * 27. Remove Element
 * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

/**
 * Runtime: 4 ms, faster than 80.18% of C++ online submissions for Remove Element.
 * Memory Usage: 8.6 MB, less than 43.63% of C++ online submissions for Remove Element.
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = 0, index = 0;
        int size = nums.size();
        
        while (index < size) {
            if(nums[index] != val) {
                nums[length++] = nums[index++];
            }
            else
                index++;
        }
        return length;    
    }
};