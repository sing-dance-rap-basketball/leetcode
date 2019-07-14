/**
 * 33. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 */

/**
 * Runtime: 8 ms, faster than 18.02% of C++ online submissions for Search in Rotated Sorted Array.
 * Memory Usage: 8.7 MB, less than 49.42% of C++ online submissions for Search in Rotated Sorted Array.
 * 想在二分的基础上改 改的越来越乱……
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        if(r < 0)
            return -1;
        
        while (l < r){
            int m = (l + r)/2;
            
            if (r - l ==1) {
                if (nums[l] == target)
                    return l;
                if (nums[r] == target)
                    return r;
                break;
            }
            
            if (nums[l] < nums[m]) {
                if (target >= nums[l] && target < nums[m])
                    r = m - 1;
                else
                    l = m;
            }
            else{
                if (target >= nums[m] && target <= nums[r])
                    l = m;
                else
                    r = m;   
            }
        }
        return target == nums[l] ? l : -1;
    }
};