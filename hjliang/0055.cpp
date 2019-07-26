/**
 * 55. Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 */

/**
 * Runtime: 504 ms, faster than 14.22% of C++ online submissions for Jump Game.
 * Memory Usage: 10.1 MB, less than 28.00% of C++ online submissions for Jump Game.
 * 递归回去了…… 没想到什么明显提高效率的方法……
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return true;
        
        return canGetIndex(nums, size - 1);
    }
    
    bool canGetIndex(vector<int>& nums, int index) {
        if (index == 0 && nums[index] != 0)
            return true;
        
        for (int i = 0; i < index; ++i) {
            if (nums[i] + i >= index) {
                return canGetIndex(nums,i);
            }
        }
        
        return false;
    }
};