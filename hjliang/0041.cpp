/**
 * 41. First Missing Positive
 * Given an unsorted integer array, find the smallest missing positive integer.
 */

/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
 * Memory Usage: 8.6 MB, less than 61.58% of C++ online submissions for First Missing Positive.
 * 
 * to void extra space, use the original vector to put every num to it's own place
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        cout << size << endl;
        for (int i = 0; i < size;) {
            if (nums[i] != i + 1 && nums[i] > 0 && nums[i] < size 
                                                && nums[nums[i] - 1] != nums[i])
                swap(nums[i],nums[nums[i] - 1]);
            else
                ++i;
        }
        
        int ret = 0;
        for (; ret < size; ++ret) {
            if (nums[ret] != ret + 1)
                return ret + 1;
        }

        return ret + 1;
    }
};
