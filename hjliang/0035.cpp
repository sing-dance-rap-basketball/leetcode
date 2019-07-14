/**
 * 35. Search Insert Position
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

/**
 * Runtime: 4 ms, faster than 99.11% of C++ online submissions for Search Insert Position.
 * Memory Usage: 8.9 MB, less than 29.27% of C++ online submissions for Search Insert Position.
 * 这三道题让我学会了二分法……
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if(r == -1)
            return 0;
        
        while (l <= r) {
            int m = (l + r)/2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target) 
                r = m - 1;
            else
                l = m + 1;
        }
        int indexTmp = l <= (nums.size() - 1) ? l : (nums.size() - 1);
        if (nums[indexTmp] < target)
            return indexTmp + 1;
        else
            return indexTmp;
    }
};