/**
 * 34. Find First and Last Position of Element in Sorted Array
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

/**
 * Runtime: 8 ms, faster than 89.84% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
 * Memory Usage: 10.2 MB, less than 78.45% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (r == -1)
            return vector<int>{-1,-1};
        if (r == 0) {
            if (nums[r] == target)
                return vector<int>{r,r};
        }
        cout << l << " " << r << endl;
        while (l <= r) {
            int m = (l + r)/2;
            if(nums[m] == target) {
                l = m; r = m;
                while (l - 1 > -1 && nums[l - 1] == target)
                    --l;
                while (r + 1 <= nums.size() - 1 && nums[r + 1] == target)
                    ++r;
                return vector<int>{l,r};
            }
            else if (nums[m] > target) 
                r = m - 1;
            else
                l = m + 1;
        }
        return vector<int>{-1,-1};
    }
};